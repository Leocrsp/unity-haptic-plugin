#ifndef PLUGIN_HEADER
#define PLUGIN_HEADER
#define _WINSOCKAPI_
#define LEO_API __declspec(dllexport)

#include <Windows.h>
#include <HD/hd.h>
#include <HL/hl.h>
//#include <HDU/hduError.h>

//#include "RenderableClass.h"
#include "AuxClass.h"

extern "C" {

	LEO_API void PluginInitialization(AuxClass* aux);

	LEO_API void PluginCleanUp(AuxClass* aux);

	LEO_API void AssignPopthrough(AuxClass* aux, int id, float val);

	LEO_API void AssignStaticFriction(AuxClass* aux, int id, float val);

	LEO_API void AssignDynamicFriction(AuxClass* aux, int id, float val);

	LEO_API void AssignDamping(AuxClass* aux, int id, float val);

	LEO_API void AssignStiffness(AuxClass* aux, int id, float val);

	LEO_API void CreateObjectMesh(AuxClass* aux, int id, int* triangles, int triSize, float* vertices, int vertSize, double* transform);
	
	LEO_API void Render(AuxClass* aux);

};

#endif