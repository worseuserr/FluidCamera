#include "Core/Feature.h"
#include "Core/Runtime.h"

FluidCamera::Logger *FluidCamera::Feature::GetLogger() const
{
	return (RT->GetLogger());
}
