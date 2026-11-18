#include "Core/Runtime.h"

using namespace FluidCamera;

Runtime::Runtime()
{
	Active = true;
}

bool Runtime::Tick()
{
	// Actual tick logic comes here soon.
	if (ExitRequested)
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
}
