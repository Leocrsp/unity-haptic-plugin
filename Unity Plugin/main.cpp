#include "header.h"

LEO_API void init() {

	HHD hHD = hdInitDevice(HD_DEFAULT_DEVICE);
	//hdEnable(HD_FORCE_OUTPUT);
	if (HD_DEVICE_ERROR(hdGetError())) {

		exit(-1);

	}

	HHLRC hHLRC = hlCreateContext(hHD);
	hlMakeCurrent(hHLRC);


}