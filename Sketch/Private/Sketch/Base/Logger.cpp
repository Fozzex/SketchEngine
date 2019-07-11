#include "Sketch/Base/Logger.h"
#include <assert.h>

namespace sk
{
	Logger::Logger(const std::string& outputFile)
	{
		m_OutputFile.open(outputFile);
		assert(m_OutputFile);
	}

	Logger::~Logger()
	{
		m_OutputFile.close();
	}

	void Logger::Log()
	{
		std::string prefix;
		switch (m_Level)
		{
		case LogLevel::Info:
			prefix = "INFO";
			break;
		case LogLevel::Warning:
			prefix = "WARNING";
			break;
		case LogLevel::Error:
			prefix = "ERROR";
			break;
		case LogLevel::Fatal:
			prefix = "FATAL";
			break;
		}
		
		m_Log << "\n";
		m_OutputFile << "[" + prefix + "] " << m_Log.str();
		m_OutputFile << std::flush;

		m_Log.str(std::string());
	}
}
