#include "header.h"

LEO_API void PluginInitialization(AuxClass* aux) {

	aux = new AuxClass();
	aux->m_hhd = hdInitDevice(HD_DEFAULT_DEVICE);
	//hdEnable(HD_FORCE_OUTPUT);
	HDErrorInfo error;
	if (HD_DEVICE_ERROR(error = hdGetError()))
	{
		//hduPrintError(stderr, &error, "Failed to initialize haptic device");
		fprintf(stderr, "\nPress any key to quit.\n");
		getchar();
		exit(-1);
	}

	aux->m_hhlrc = hlCreateContext(aux->m_hhd);
	hlMakeCurrent(aux->m_hhlrc);
	hlDisable(HL_USE_GL_MODELVIEW);
	hlEnable(HL_HAPTIC_CAMERA_VIEW);
	hlTouchableFace(HL_FRONT);
	hlTouchModel(HL_CONTACT);

}

LEO_API void PluginCleanUp(AuxClass* aux) {

	hlMakeCurrent(NULL);
	hlDeleteContext(aux->m_hhlrc);
	hdDisableDevice(aux->m_hhd);
	delete aux;
	aux = NULL;

}

LEO_API void AssignStiffness(AuxClass* aux, int id, float val) {

	RenderableClass* object = &aux->m_objects[id];
	if (object)
		object->m_stiffness = val;
	else {

		fprintf(stdout, "\n Invalid object ID");
		return;

	}

}

LEO_API void AssignDamping(AuxClass* aux, int id, float val) {

	RenderableClass* object = &aux->m_objects[id];
	if (object)
		object->m_damping = val;
	else {

		fprintf(stdout, "\n Invalid object ID");
		return;

	}

}

LEO_API void AssignDynamicFriction(AuxClass* aux, int id, float val) {

	RenderableClass* object = &aux->m_objects[id];
	if (object)
		object->m_dynamicFriction = val;
	else {

		fprintf(stdout, "\n Invalid object ID");
		return;

	}

}

LEO_API void AssignStaticFriction(AuxClass* aux, int id, float val) {

	RenderableClass* object = &aux->m_objects[id];
	if (object)
		object->m_staticFriction = val;
	else {

		fprintf(stdout, "\n Invalid object ID");
		return;

	}

}

LEO_API void AssignPopthrough(AuxClass* aux, int id, float val) {

	RenderableClass* object = &aux->m_objects[id];
	if (object)
		object->m_popthrough = val;
	else {

		fprintf(stdout, "\n Invalid object ID");
		return;

	}

}

LEO_API void CreateObjectMesh(AuxClass* aux, int id, int* triangles, int triSize, float* vertices, int vertSize, double* transform) {

	/*if an object with such an id exists, overwrite the mesh*/
	if (aux->m_objects.count(id)) {

		RenderableClass& object = aux->m_objects[id];
		/*delete previous vertices and triangles*/
		delete object.m_triangles;
		delete object.m_vertices;
		delete object.m_transform;
		/*assign new vertices and triangles*/
		object.m_triangles = &triangles[0];
		object.m_vertices = vertices;
		object.m_transform = transform;
		object.m_triSize = triSize;
		object.m_vertSize = vertSize;

	}
	/*If it doesnb't exist, create it*/
	else {

		aux->m_objects.insert(std::pair<int, RenderableClass>(id, RenderableClass()));
		RenderableClass& object = aux->m_objects[id];
		object.m_id = id;
		object.m_triangles = triangles;
		object.m_vertices = vertices;
		object.m_transform = transform;
		object.m_triSize = triSize;
		object.m_vertSize = vertSize;

	}


}

LEO_API void Render(AuxClass* aux) {

	hlBeginFrame();

	for(const auto& object : aux->m_objects) {

		hlMaterialf(HL_FRONT_AND_BACK, HL_STIFFNESS, object.second.m_stiffness);
		hlMaterialf(HL_FRONT_AND_BACK, HL_DAMPING, object.second.m_damping);
		hlMaterialf(HL_FRONT_AND_BACK, HL_STATIC_FRICTION, object.second.m_staticFriction);
		hlMaterialf(HL_FRONT_AND_BACK, HL_DYNAMIC_FRICTION, object.second.m_dynamicFriction);
		hlMaterialf(HL_FRONT_AND_BACK, HL_POPTHROUGH, object.second.m_popthrough);

		hlBeginShape(HL_SHAPE_FEEDBACK_BUFFER, object.second.m_id);

		glBegin(GL_TRIANGLES);
		
		for(int i = 0; i < object.second.m_vertSize; i = i+3) {

			glVertex3f(object.second.m_vertices[i], object.second.m_vertices[i+1], object.second.m_vertices[i+2]);

		}

		glEnd();

		hlEndShape();

	}

	hlEndFrame();

}