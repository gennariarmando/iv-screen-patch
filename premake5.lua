workspace "iv-screen-patch"
	configurations { "Release", "Debug" }
	platforms { "Win32" }
	architecture "x32"
	location "project_files"
   
project "iv-screen-patch"
	files {
		"source/**.*",
	}
	
	includedirs { 
		"source/**"
	}
	
	kind "SharedLib"
	language "C++"
	targetdir "output/asi"
	objdir ("output/obj")
	targetextension ".asi"
	characterset ("MBCS")
	linkoptions "/SAFESEH:NO"
	buildoptions { "-std:c++latest", "/Zc:threadSafeInit-", "/Zc:strictStrings" }
	defines { "_CRT_SECURE_NO_WARNINGS", "_CRT_NON_CONFORMING_SWPRINTFS" }
    disablewarnings { "4244", "4800", "4305", "4073", "4838", "4996", "4221", "4430" }
	
	filter "configurations:Debug"
		targetname "IVScreenPatch"
		defines { "DEBUG" }
		staticruntime "on"
		symbols "On"
		debugdir "$(GTA_IV_DIR)"
		debugcommand "$(GTA_IV_DIR)/GTAIV/PlayGTAIV.exe"

	filter "configurations:Release"
		targetname "IVScreenPatch"
		defines { "NDEBUG" }
		optimize "On"
		staticruntime "on"
		debugdir "$(GTA_IV_DIR)"
		debugcommand "$(GTA_IV_DIR)/GTAIV/PlayGTAIV.exe"