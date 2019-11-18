workspace "GameEngine"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

includedir = {}
includedir["GLFW"] = "GameEngine/vendor/GLFW/include"
includedir["Glad"] = "GameEngine/vendor/Glad/include"
	
	
include "GameEngine/vendor/GLFW"
include "GameEngine/vendor/Glad"
	
project "GameEngine"
	location "GameEngine"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "gepch.h"
	pchsource "GameEngine/src/gepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{includedir.GLFW}",
		"%{includedir.Glad}"
		
	}
	
	links
	{
		"GLFW",
		"Glad",
		"opengl32.lib"
	}
	
	
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"
	
		defines
		{
			"GE_PLATFORM_WINDOWS",
			"GE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "GE_DEBUG"
		buildoptions "/MDd"
		symbols "on"
		
	filter "configurations:Release"
		defines "GE_RELEASE"
		buildoptions "/MD"
		optimize "on"
		
	filter "configurations:Dist"
		defines "GE_DIST"
		buildoptions "/MD"
		optimize "on"
		
		
		
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"GameEngine/vendor/spdlog/include",
		"GameEngine/src"
	}
	
	links
	{
		"GameEngine"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"
	
		defines
		{
			"GE_PLATFORM_WINDOWS",
		}
		
	filter "configurations:Debug"
		defines "GE_DEBUG"
		buildoptions "/MDd"
		symbols "on"
		
	filter "configurations:Release"
		defines "GE_RELEASE"
		buildoptions "/MD"
		optimize "on"
		
	filter "configurations:Dist"
		defines "GE_DIST"
		buildoptions "/MD"
		optimize "on"