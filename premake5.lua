workspace "zephyr"
	architecture "x64"
	startproject "Sandbox"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "zephyr"
	location "zephyr"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-temp/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/packages/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"ZR_PLATFORM_WINDOWS",
			"ZR_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ZR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZR_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-temp/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"zephyr/packages/spdlog/include",
		"zephyr/src"
	}

	links
	{
		"zephyr"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.19041.0"

		defines
		{
			"ZR_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ZR_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ZR_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ZR_DIST"
		optimize "On"