#pragma once

namespace FluidCamera
{
	class Feature
	{
		friend class	Runtime;
		Runtime			*RT;

	public:
		Feature() = default;
		virtual				~Feature() = default;
		virtual const char	*GetName() const = 0;
		virtual void		Start() {}
		virtual void		Tick(const float dTime) {}
		Runtime				*GetRuntime() const
		{
			return (RT);
		}
		template			<typename RuntimeT>
		RuntimeT			*GetRuntime() const
		{
			return (static_cast<RuntimeT *>(RT));
		}
	};
}
