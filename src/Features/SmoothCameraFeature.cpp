#include "Features/SmoothCameraFeature.h"
#include "FluidCameraRuntime.h"
#include "ScriptHookV/inc/natives.h"

using namespace FluidCamera;

const char *SmoothCameraFeature::GetName() const
{
	return ("SmoothCameraFeature");
}

void SmoothCameraFeature::Start()
{
	CameraController = GetRuntime<FluidCameraRuntime>()->CameraController;
	CameraController->CameraRelativeRotations[GetName()] = Vec3();
	CameraController->CameraRelativeOffsets["SmoothCameraWorldPosition"] = Vec3();
}

void SmoothCameraFeature::Tick(const float deltaTime)
{
	// Test code
	CameraController->CameraRelativeRotations[GetName()] = Vec3::FromGTARot(CAM::GET_GAMEPLAY_CAM_ROT(2));
	CameraController->CameraRelativeOffsets["SmoothCameraWorldPosition"] = Vec3(PED::GET_PED_BONE_COORDS(PLAYER::PLAYER_PED_ID(), 31086, 0, 0, 0));
}
