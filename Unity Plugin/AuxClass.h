#ifndef AUX_CLASS
#define AUX_CLASS

//#define _WIN‡SOCKAPI_
#include <Windows.h>
#include <map>
#include <HD/hd.h>
#include <HL/hl.h>
#include "RenderableClass.h"

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