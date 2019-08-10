#pragma once

// Exporting
#ifdef _MSC_VER
#	pragma warning(disable : 4251)
#	ifdef SKETCH_DLL
#		define SKETCH_API __declspec(dllexport)
#	else
#		define SKETCH_API __declspec(dllimport)
#	endif
#else
#	define SKETCH_API
#endif

// Data types
namespace sk
{
#	ifdef _MSC_VER
		using Int64  = signed   __int64;
		using UInt64 = unsigned __int64;
#	else
		using Int64  = signed   long long;
		using UInt64 = unsigned long long;
#	endif
}

#define BIND_EVENT_METHOD(fn) std::bind(fn, this, std::placeholders::_1)
