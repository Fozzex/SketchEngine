#include "Sketch/Base/FileSystem.h"

#if defined(SKETCH_PLATFORM_WINDOWS)

#include "Sketch/Platform/Win32/Win32CleanupApi.h"

namespace sk
{
	bool FileSystem::PathExists(const std::string& path)
	{
		if (path.empty())
			return true;

		return GetFileAttributesA(path.c_str());
	}

	bool FileSystem::FileExists(const std::string& path)
	{
		uint32_t data = GetFileAttributesA(path.c_str());
		return (data != 0xFFFFFFFF) && !(data & FILE_ATTRIBUTE_DIRECTORY);
	}

	bool FileSystem::DirectoryExists(const std::string& path)
	{
		uint32_t data = GetFileAttributesA(path.c_str());
		return (data != 0xFFFFFFFF) && (data & FILE_ATTRIBUTE_DIRECTORY);
	}

	bool FileSystem::CreateDirectory(const std::string& path)
	{
		return CreateDirectoryA(path.c_str(), NULL);
	}
}

#endif
