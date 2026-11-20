#pragma once
#include <string>
#include <unordered_map>
#include "Core/Feature.h"
#include "Core/Vec3.h"
#include "ScriptHookV/inc/types.h"

namespace FluidCamera
{
	class	CameraControllerFeature : public Feature
	{
	protected:
		Cam		Camera = 0;
		void	SetGTACameraRelativeTransform(const Vec3 &pos, const Vec3 &rot) const;

	public:
		std::unordered_map<std::string, Vec3>	CameraRelativeRotations;
		std::unordered_map<std::string, Vec3>	CameraRelativeOffsets;

		const char	*GetName() const override;
		void		Start() override;
		void		Tick(float deltaTime) override;
	};
}
