#pragma once
#ifndef PLUGIN_HEADER
#define PLUGIN_HEADER

#include <Windows.h>
#include <iostream>
#include <HD/hd.h>
#include <HD/hdExport.h>
#include <HL/hl.h>
#include <QHHeadersGLUT.h>
#include <QHHeadersWin32.h>
#include <HDU/hdu.h>
#include <HLU/hlu.h>
#include <GL/glut.h>

#if define DLL_EXPORT
#define LEO_API __declspec(dllexport)
#else
#define LEO_API __declspec(dllexport)
#endif

extern "C" {

	LEO_API void init();

};

#endif