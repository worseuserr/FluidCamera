#include "Features/CameraControllerFeature.h"
#include <format>
#include "ScriptHookV/inc/natives.h"

using namespace FluidCamera;

void CameraControllerFeature::SetGTACameraRelativeTransform(const Vec3 &pos, const Vec3 &rot) const
{
	const Vec3	gtaRot = rot.ToGTARot();
	CAM::SET_CAM_COORD(Camera, pos.X, pos.Y, pos.Z);
	CAM::SET_CAM_ROT(Camera, gtaRot.X, gtaRot.Y, gtaRot.Z, 2);
	CAM::SET_CAM_ACTIVE(Camera, true);
	CAM::SET_CAM_NEAR_CLIP(Camera, 0.25);
	CAM::RENDER_SCRIPT_CAMS(true, false, 0, false, false);

	// CAM::SET_GAMEPLAY_CAM_RELATIVE_HEADING(-rot.Z);
	// CAM::SET_GAMEPLAY_CAM_RELATIVE_PITCH(rot.Y, 1.f);
}

const char *CameraControllerFeature::GetName() const
{
	return ("CameraControllerFeature");
}

void CameraControllerFeature::Start()
{
	Camera = CAM::CREATE_CAM(const_cast<char *>("DEFAULT_SCRIPTED_CAMERA"), true);
}

void CameraControllerFeature::Tick(const float deltaTime)
{
	Vec3	finalRotation;
	Vec3	finalOffset;

	if (!CAM::DOES_CAM_EXIST(Camera))
		Camera = CAM::CREATE_CAM(const_cast<char *>("DEFAULT_SCRIPTED_CAMERA"), true);
	for (const std::pair<std::string, Vec3> entry : CameraRelativeRotations)
		finalRotation += entry.second;
	finalRotation.NormalizeRotation();
	for (const std::pair<std::string, Vec3> entry : CameraRelativeOffsets)
		finalOffset += entry.second;
	if (GetLogger())
		GetLogger()->Debug(std::format("[ROT X: {}, Y: {}, Z: {}] POS: X: {}, Y: {}, Z: {}]",
			finalRotation.X, finalRotation.Y, finalRotation.Z,
			finalOffset.X, finalOffset.Y, finalOffset.Z));
	SetGTACameraRelativeTransform(finalOffset, finalRotation);
}
