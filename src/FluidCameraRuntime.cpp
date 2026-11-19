#include "FluidCameraRuntime.h"
#include "Features/SmoothCameraFeature.h"

using namespace FluidCamera;

FluidCameraRuntime::FluidCameraRuntime()
{
	SmoothCamera = InitializeFeature<SmoothCameraFeature>();
}
