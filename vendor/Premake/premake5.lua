workspace "Pong2D"
	architecture "x86"
	configurations { "Debug", "Release"	}
	entrypoint "mainCRTStartup"
	output_dir = "%{cfg.system}_%{cfg.buildcfg}_%{cfg.architecture}"
	location "../../"
	
project "Pong2D"
	kind "WindowedApp"
	language "C++"
	location "../../Pong2D/"
	
	targetdir("../../Pong2D/" ..output_dir.. "/")
	objdir("../../Pong2D/" ..output_dir.. "/data/obj/")
	
	files {
		"../../src/*.cpp",
		"../../src/*.h"
	}
	
	includedirs {"../SFML/include"}
	
	libdirs {"../SFML/lib"}
	
	links {"opengl32.lib", "freetype.lib", "winmm.lib", "gdi32.lib", "flac.lib", "vorbisenc.lib",
	"vorbisfile.lib", "ogg.lib", "ws2_32.lib"}
	
	filter "system:windows"
		systemversion "latest"
	
		defines {"SFML_STATIC"}
	
	filter "configurations:Debug"
		runtime "Debug"
		symbols "On"
		
		links {"sfml-graphics-s-d.lib", "sfml-window-s-d.lib", "sfml-system-s-d.lib"}
	
	filter "configurations:Release"
		runtime "Release"
		optimize "On"
		
		links {"sfml-graphics-s.lib", "sfml-window-s.lib", "sfml-system-s.lib"}