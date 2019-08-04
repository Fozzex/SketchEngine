#include "Sketch/Base/Logger.h"
#include <assert.h>

#include "Sketch/Base/FileSystem.h"

namespace sk
{
	std::unordered_map<unsigned int, std::string> Logger::s_PrefixMap
	{
		std::make_pair(static_cast<unsigned int>(LogLevel::Info), "INFO"),
		std::make_pair(static_cast<unsigned int>(LogLevel::Warning), "WARNING"),
		std::make_pair(static_cast<unsigned int>(LogLevel::Error), "ERROR"),
		std::make_pair(static_cast<unsigned int>(LogLevel::Fatal), "FATAL")
	};

	Logger::Logger(const std::string& outputFile)
	{
		size_t directoryDelim = outputFile.find_last_of("/\\");
		std::string directory = outputFile.substr(0, directoryDelim);

		if (!FileSystem::DirectoryExists(directory))
		{
			directoryDelim = directory.find_last_of("/\\");
			std::string nestedDirectory = directory.substr(0, directoryDelim);

			bool result = FileSystem::DirectoryExists(nestedDirectory);
			assert(result && "Attempted to create file in non-existant nested directories");

			FileSystem::CreateDirectory(directory);
		}

		m_OutputFile.open(static_cast<std::string>(outputFile));
		assert(m_OutputFile && "Failed to create log file");

		this->SetLevel(LogLevel::Info);
	}

	Logger::~Logger()
	{
		m_OutputFile.close();
	}

	void Logger::SetLevel(LogLevel level)
	{
		m_Level = level;
		m_Prefix = this->GetPrefix(level);
	}

	void Logger::Log()
	{
		m_Log << "\n";
		m_OutputFile << "[" + m_Prefix + "] " << m_Log.str();
		m_OutputFile << std::flush;

		m_Log.str(std::string());
	}
}
