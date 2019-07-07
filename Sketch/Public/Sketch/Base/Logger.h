#pragma once
#include <string>
#include <sstream>
#include <fstream>

#include "Core.h"

namespace sk
{
	enum class LogLevel
	{
		Info = 0,
		Warning,
		Error,
		Fatal
	};

	class SKETCH_API Logger
	{
	public:

		Logger(const std::string& outputFile);
		~Logger();

		Logger(const Logger&) = delete;
		Logger(Logger&&) = delete;
		Logger& operator=(const Logger&) = delete;
		Logger& operator=(Logger&&) = delete;

		template<typename T, typename... Args>
		void Log(const T& msg, const Args& ... args);

		inline void SetLevel(LogLevel level) { m_Level = level; }

	private:

		void Log();

	private:

		std::ofstream m_OutputFile;
		std::stringstream m_Log;

		LogLevel m_Level = LogLevel::Info;

	};

	template<typename T, typename... Args>
	void Logger::Log(const T& msg, const Args& ... args)
	{
		m_Log << msg;
		this->Log(args...);
	}
}
