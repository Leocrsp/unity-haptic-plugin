#ifndef RENDERABLE_CLASS
#define RENDERABLE_CLASS

#define _WINSOCKAPI_

#include <GL/freeglut.h>
#include <HD/hd.h>
#include <HL/hl.h>

class RenderableClass
{
public:

	/*Attributes*/
	int* m_triangles;
	float* m_vertices;
	int m_id;
	double* m_transform;
	int m_vertSize;
	int m_triSize;

	HDfloat m_stiffness;
	HDfloat m_popthrough;
	HDfloat m_damping;
	HDfloat m_staticFriction;
	HDfloat m_dynamicFriction;

	/*Methods*/
	RenderableClass();
	~RenderableClass();
};

#endif