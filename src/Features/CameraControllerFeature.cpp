#include "Features/CameraControllerFeature.h"

using namespace FluidCamera;

void CameraControllerFeature::SetGTACameraRelativeTransform(const Vec3 &pos, const Vec3 &rot) const
{
	// todo
}

const char *CameraControllerFeature::GetName() const
{
	return ("CameraControllerFeature");
}

void CameraControllerFeature::Start()
{
	// ...
}

void CameraControllerFeature::Tick(const float dTime)
{
	Vec3	finalRotation;
	Vec3	finalOffset;

	for (const std::pair<std::string, Vec3> entry : CameraRelativeRotations)
		finalRotation += entry.second;
	finalRotation.NormalizeRotation();
	for (const std::pair<std::string, Vec3> entry : CameraRelativeOffsets)
		finalOffset += entry.second;
	SetGTACameraRelativeTransform(finalOffset, finalRotation);
}
