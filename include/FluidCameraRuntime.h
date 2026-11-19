#pragma once
#include "Core/Runtime.h"

namespace FluidCamera
{
	class SmoothCameraFeature;

	class	FluidCameraRuntime : public Runtime
	{
	public:
		SmoothCameraFeature	*SmoothCamera;

		FluidCameraRuntime();
	};
}
