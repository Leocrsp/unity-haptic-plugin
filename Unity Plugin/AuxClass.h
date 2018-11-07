#ifndef AUX_CLASS
#define AUX_CLASS

#include "header.h"

class AuxClass
{
public:

	/*Attrtibutes*/
	HHD m_hhd;
	HHLRC m_hhlrc;
	std::map<int, RenderableClass> m_objects;

	AuxClass();
	~AuxClass();
};

#endif // !AUX_CLASS