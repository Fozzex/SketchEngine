#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <unordered_map>

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
		static std::unordered_map<unsigned int, std::string> s_PrefixMap;
	public:

		explicit Logger(const std::string& outputFile);
		~Logger();

		Logger(const Logger&) = delete;
		Logger(Logger&&) = delete;
		Logger& operator=(const Logger&) = delete;
		Logger& operator=(Logger&&) = delete;

		template<typename T, typename... Args>
		void Log(const T& msg, Args&& ... args);

		void SetLevel(LogLevel level);

		static inline const std::string& GetPrefix(LogLevel level) 
		{ 
			return s_PrefixMap[static_cast<unsigned int>(level)]; 
		}

	private:

		void Log();

	private:

		std::ofstream m_OutputFile;
		std::stringstream m_Log;

		LogLevel m_Level;
		std::string m_Prefix;

	};

	template<typename T, typename... Args>
	void Logger::Log(const T& msg, Args&& ... args)
	{
		m_Log << msg;
		this->Log(std::forward<decltype(args)>(args)...);
	}
}
