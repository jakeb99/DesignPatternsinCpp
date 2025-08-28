#pragma once

#include <iostream>


class Log
{
public:
	enum LogLevel {
		LevelError = 0,
		LevelWarn = 1,
		LevelInfo = 2,
		LevelDebug = 3
	};

	static void SetLogLevel(LogLevel level)
	{
		m_CurrentLogLevel = level;
	}

	template<typename T, typename... Types>
	static void Error(T arg1, Types... arg2)
	{
		print(LogLevel::LevelError, arg1, arg2...);
	}

	template<typename T, typename... Types>
	static void Warn(T arg1, Types... arg2)
	{
		print(LogLevel::LevelWarn, arg1, arg2...);
	}

	template<typename T, typename... Types>
	static void Info(T arg1, Types... arg2)
	{
		print(LogLevel::LevelInfo, arg1, arg2...);
	}

	template<typename T, typename... Types>
	static void Debug(T arg1, Types... arg2)
	{
		print(LogLevel::LevelDebug, arg1, arg2...);
	}

	Log() = delete;

private:
	static LogLevel m_CurrentLogLevel;
	static bool m_PrintPrefix;

	template<typename T, typename... Types>
	static void print(LogLevel level, T arg1, Types... arg2)
	{
		const char* logColors[4] = {
			"\033[31m",
			"\033[33m",
			"\033[0m",
			"\033[36m"
		};

		const char* logPrefix[4] = {
			"[ERROR]:",
			"[WARN]:",
			"[INFO]:",
			"[DEBUG]:"
		};

		if (m_CurrentLogLevel >= level)
		{
			if (m_PrintPrefix)
			{
				std::cout << logColors[static_cast<unsigned int>(level)] << logPrefix[static_cast<unsigned int>(level)];
				m_PrintPrefix = false;
			}

			std::cout << logColors[static_cast<unsigned int>(level)] << arg1;

			print(level, arg2...);
		}
	}

	static void print(LogLevel level)
	{
		if (m_CurrentLogLevel >= level)
		{
			std::cout << "\033[0m" << std::endl;
			m_PrintPrefix = true;
		}
	}
};
