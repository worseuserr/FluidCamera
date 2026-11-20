#pragma once
#include "Core/Runtime.h"
#include "Features/SmoothCameraFeature.h"
#include "Features/CameraControllerFeature.h"

namespace FluidCamera
{
	class	FluidCameraRuntime : public Runtime
	{
	public:
		SmoothCameraFeature		*SmoothCamera;
		CameraControllerFeature	*CameraController;

		FluidCameraRuntime();
	};
}
