#pragma once
#include "Sketch/Base/Core.h"

#include <string>

namespace sk
{
	class SKETCH_API FileSystem
	{
	public:

		/* Check if a file or directory exists at this path */
		static bool PathExists(const std::string& path);
		/* Check if a file exists at this path */
		static bool FileExists(const std::string& path);
		/* Check if a directory exists at this path */
		static bool DirectoryExists(const std::string& path);

		/* Create specified directory */
		static bool CreateDirectory(const std::string& path);

	};
}
