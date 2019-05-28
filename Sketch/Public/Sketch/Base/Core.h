#pragma once
#pragma warning(disable : 4251)

#ifdef _MSC_VER
#	ifdef SKETCH_DLL
#		define SKETCH_API __declspec(dllexport)
#	else
#		define SKETCH_API __declspec(dllimport)
#	endif
#else
#	define SKETCH_API
#endif
