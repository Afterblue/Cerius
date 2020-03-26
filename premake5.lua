workspace "Cerius"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Cerius"
	location "Cerius"
	kind "SharedLib"
	language "C"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c"
	}

	filter "system:windows"
		cdialect "Default"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CRS_PLATFORM_WINDOWS",
			"CRS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CRS_DEBUG"
		symbols "On"

	filter "configurations:Relase"
		defines "CRS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CRS_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c"
	}

	includedirs
	{
		"Cerius/src"
	}

	links
	{
		"Cerius"
	}

	filter "system:windows"
		cdialect "Default"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CRS_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "CRS_DEBUG"
		symbols "On"

	filter "configurations:Relase"
		defines "CRS_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "CRS_DIST"
		optimize "On"