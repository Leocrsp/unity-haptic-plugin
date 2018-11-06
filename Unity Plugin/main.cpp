#include "header.h"

LEO_API void init() {

	HHD hHD = hdInitDevice(HD_DEFAULT_DEVICE);

	if (HD_DEVICE_ERROR(hdGetError())) {

		exit(-1);

	}
	hdEnable(HD_FORCE_OUTPUT);
	hdStartScheduler();
	hdMakeCurrentDevice(hHD);

	if (!hdIsEnabled(HD_FORCE_OUTPUT)) {

		hdEnable(HD_FORCE_OUTPUT);

	}


}

