#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Feature.h"

namespace FluidCamera
{
	// Basically a small entity (runtime) component (feature) system.
	class	Runtime
	{
		float	LastMeasuredTimeSeconds;
		Logger	*Logger = nullptr;

	protected:
		std::vector<std::unique_ptr<Feature>>	Features;
		bool		HasStartedFeatures = false;
		bool		Active = true;
		bool		ExitRequested = false;
		std::string	ExitReason;

		template	<typename FeatureT, typename... ConstructorArgs>
		requires	(std::is_base_of_v<Feature, FeatureT> && std::is_constructible_v<FeatureT, ConstructorArgs...>)
		FeatureT	*InitializeFeature(ConstructorArgs&&... args)
		{
			std::unique_ptr<FeatureT>	res = std::make_unique<FeatureT>(std::forward<ConstructorArgs>(args)...);
			FeatureT					*raw = res.get();
			Features.push_back(std::move(res));
			raw->RT = this;
			return (raw);
		}

	public:
		Runtime();
		virtual				~Runtime() = default;
		// Returns true and does nothing internally if ExitRequested is true. First tick runs Feature.Start() instead of Feature.Tick().
		virtual bool		Tick();
		void				RequestExit(std::string reason);
		bool				IsExitRequested() const;
		bool				IsActive() const;
		// Returns nullptr if exit reason is empty. Exit reason is not reset after a revive, but is reassigned if exited again.
		const std::string	*GetExitReason() const;
		// Restart after exit, assuming error handling was done and the loop can continue.
		void				Revive();
		FluidCamera::Logger	*GetLogger() const;
		static float		GetEpochTimeSeconds();
	};
}
