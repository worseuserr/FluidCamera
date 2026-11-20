cmake_minimum_required(VERSION 4.2)
project(FluidCamera)

set(CMAKE_CXX_STANDARD 20)
set(SDK_PATH "external/ScriptHookV")

add_library(FluidCamera SHARED
		src/DllMain.cpp
		src/Core/Runtime.cpp
		src/Core/Feature.cpp
		src/Features/SmoothCameraFeature.cpp
		src/FluidCameraRuntime.cpp
		src/Features/CameraControllerFeature.cpp
		src/Core/Vec3.cpp
)

target_include_directories(FluidCamera PRIVATE
		include
		external
)

target_link_directories(FluidCamera PRIVATE
		"${SDK_PATH}/lib"
)

target_link_libraries(FluidCamera PRIVATE
		ScriptHookV.lib
)

target_compile_options(FluidCamera PRIVATE
		/EHsc
)

set_target_properties(FluidCamera PROPERTIES
	SUFFIX ".asi"
)
