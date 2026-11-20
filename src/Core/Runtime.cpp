#include "Core/Runtime.h"
#include <chrono>

using namespace FluidCamera;

Runtime::Runtime()
{
	LastMeasuredTimeSeconds = GetEpochTimeSeconds();
	Active = true;
}

bool Runtime::Tick()
{
	const float	currTime = GetEpochTimeSeconds();
	const float	deltaTime = currTime - LastMeasuredTimeSeconds;

	LastMeasuredTimeSeconds = currTime;
	for (const std::unique_ptr<Feature> &feat : Features)
	{
		try
		{
			if (HasStartedFeatures)
				feat->Tick(deltaTime);
			else
				feat->Start();
		}
		catch (std::exception e)
		{
			RequestExit(
				std::format("Exception caught in [{}] function {}, what: [{}]",
					feat->GetName(), HasStartedFeatures ? "Start()" : "Tick()",
					e.what()));
			break ;
		}
	}
	if (!HasStartedFeatures)
		HasStartedFeatures = true;
	if (ExitRequested || !Active)
	{
		if (Active)
			Active = false;
		return (true);
	}
	return (false);
}

void Runtime::RequestExit(std::string reason)
{
	ExitReason = std::move(reason);
}

bool Runtime::IsExitRequested() const
{
	return (ExitRequested);
}

bool Runtime::IsActive() const
{
	return (Active);
}

const std::string *Runtime::GetExitReason() const
{
	if (ExitReason.empty())
		return (nullptr);
	return (&ExitReason);
}

void Runtime::Revive()
{
	ExitRequested = false;
	Active = true;
	LastMeasuredTimeSeconds = GetEpochTimeSeconds();
}

Logger *Runtime::GetLogger() const
{
	return (Logger);
}

float Runtime::GetEpochTimeSeconds()
{
	return (std::chrono::duration_cast<std::chrono::duration<float>>(std::chrono::steady_clock::now().time_since_epoch()).count());
}
