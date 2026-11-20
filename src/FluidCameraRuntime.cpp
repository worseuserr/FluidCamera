#include "FluidCameraRuntime.h"

using namespace FluidCamera;

FluidCameraRuntime::FluidCameraRuntime()
{
	CameraController = InitializeFeature<CameraControllerFeature>();
	SmoothCamera = InitializeFeature<SmoothCameraFeature>();
}
