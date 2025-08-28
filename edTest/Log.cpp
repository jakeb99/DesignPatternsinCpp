#include "Log.h"

// Define the static members
Log::LogLevel Log::m_CurrentLogLevel = Log::LogLevel::LevelDebug;
bool Log::m_PrintPrefix = true;