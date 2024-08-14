project "WhizzGL"
	language "C"
	kind "StaticLib"

	targetdir ("bin/%{prj.name}")
	objdir ("bin-int/%{prj.name}")

	files
	{
		"src/**.c"
	}

	includedirs
	{
		"include"
	}
