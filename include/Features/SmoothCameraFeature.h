#pragma once
#include "Core/Feature.h"

namespace FluidCamera
{
	class	SmoothCameraFeature : public Feature
	{
	public:
		const char	*GetName() const override;
		void		Start() override;
		void		Tick(float dTime) override;
	};
}
