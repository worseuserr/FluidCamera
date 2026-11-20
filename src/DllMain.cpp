#include "FluidCameraRuntime.h"
#include "Core/Runtime.h"
#include "ScriptHookV/inc/main.h"

using namespace FluidCamera;

static void FluidCameraMain()
{
	FluidCameraRuntime	rt;

	while (rt.IsActive())
	{
		rt.Tick();
		WAIT(0);
	}
	// Do proper error logging in future.
	MessageBoxA(
		nullptr,
		rt.GetExitReason()->c_str(),
		"Error",
		MB_OK | MB_ICONERROR
	);
	// throw std::exception(rt.GetExitReason()->c_str());
}

BOOL APIENTRY DllMain(const HMODULE hInstance, const DWORD reason, LPVOID lpReserved)
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
			scriptRegister(hInstance, FluidCameraMain);
			break;
		case DLL_PROCESS_DETACH:
			scriptUnregister(hInstance);
			break;
		default: break;
	}
	return TRUE;
}

