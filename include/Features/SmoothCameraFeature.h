#pragma once
#include "Core/Feature.h"

namespace FluidCamera
{
	class CameraControllerFeature;

	class	SmoothCameraFeature : public Feature
	{
	public:
		CameraControllerFeature	*CameraController = nullptr;

		const char	*GetName() const override;
		void		Start() override;
		void		Tick(float dTime) override;
	};
}
