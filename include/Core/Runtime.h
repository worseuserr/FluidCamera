#pragma once
#include <string>

namespace FluidCamera
{
	class	Runtime
	{
	protected:
		bool		Active = true;
		bool		ExitRequested = false;
		std::string	ExitReason;

	public:

		Runtime();
		virtual				~Runtime() = default;
		// Returns true and does nothing internally if ExitRequested is true.
		virtual bool		Tick();
		void				RequestExit(std::string reason);
		bool				IsExitRequested() const;
		bool				IsActive() const;
		// Returns nullptr if exit reason is empty. Exit reason is not reset after a revive, but is reassigned if exited again.
		const std::string	*GetExitReason() const;
		// Restart after exit, assuming error handling was done and the loop can continue.
		void				Revive();
	};
}
