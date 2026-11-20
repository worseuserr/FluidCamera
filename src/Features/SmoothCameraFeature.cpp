#include "Features/SmoothCameraFeature.h"
#include "FluidCameraRuntime.h"

using namespace FluidCamera;

const char *SmoothCameraFeature::GetName() const
{
	return ("SmoothCameraFeature");
}

void SmoothCameraFeature::Start()
{
	CameraController = GetRuntime<FluidCameraRuntime>()->CameraController;
	CameraController->CameraRelativeRotations[GetName()] = Vec3();
}

void SmoothCameraFeature::Tick(const float dTime)
{
	// Test code
	CameraController->CameraRelativeRotations[GetName()].RotateYaw(1.f * dTime);
}
