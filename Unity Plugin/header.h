#ifndef PLUGIN_HEADER
#define PLUGIN_HEADER

#include <Windows.h>
#include <iostream>


#if define DLL_EXPORT
#define LEO_API __declspec(dllexport)
#else
#define LEO_API __declspec(dllexport)
#endif

#include <map>
#include <HD/hd.h>
#include <HD/hdExport.h>
#include <HL/hl.h>
#include <QHHeadersGLUT.h>
#include <QHHeadersWin32.h>
#include <HDU/hdu.h>
#include <HDU/hduError.h>
#include <HLU/hlu.h>
#include <GL/glut.h>
#include "RenderableClass.h"
#include "AuxClass.h"

extern "C" {

	LEO_API void init(AuxClass* aux);

	LEO_API void CleanUp(AuxClass* aux);

	LEO_API void AssignPopthrough(AuxClass* aux, int id, double val);

	LEO_API void AssignStaticFriction(AuxClass* aux, int id, double val);

	LEO_API void AssignDynamicFriction(AuxClass* aux, int id, double val);

	LEO_API void AssignDamping(AuxClass* aux, int id, double val);

	LEO_API void AssignStiffness(AuxClass* aux, int id, double val);

	LEO_API void CreateObjectMesh(AuxClass* aux, int id, int* triangles, int triSize, float* vertices, int vertSize, double* transform);
	
	LEO_API void Render(AuxClass* aux);

};

#endif