-- Specify the name for the workspace, same as the first line of the solution directory
workspace "Catch"		 
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Catch"
	location "Catch"
	kind "SharedLib"	-- specifying that its a dll file.
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	-- now for intermediate files.
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
		-- add other files here as you make them.
	}

	includedirs
	{
		"%{prj.name}/thirdParty/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CATCH_PLATFORM_WINDOWS",
			"CATCH_BUILD_DLL"
		}

		postbuildcommands
		{
			-- so that every time we dont have to copy paste the dll to the sandbox folder.
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "CATCH_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "CATCH_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "CATCH_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"	-- specifying that its a dll file.
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	-- now for intermediate files.
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
		-- add other files here as you make them.
	}

	includedirs
	{
		"Catch/thirdParty/spdlog/include",
		"Catch/src"
	}

	links
	{
		-- specify the project name
		"Catch"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"CATCH_PLATFORM_WINDOWS"
		}

		filter "configurations:Debug"
			defines "CATCH_DEBUG"
			symbols "On"
			
		filter "configurations:Release"
			defines "CATCH_RELEASE"
			optimize "On"
			
		filter "configurations:Dist"
			defines "CATCH_DIST"
			optimize "On"