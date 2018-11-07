#include "header.h"

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

	HDdouble m_stiffness;
	HDdouble m_popthrough;
	HDdouble m_damping;
	HDdouble m_staticFriction;
	HDdouble m_dynamicFriction;
	

	/*Methods*/
	RenderableClass();
	~RenderableClass();
};
