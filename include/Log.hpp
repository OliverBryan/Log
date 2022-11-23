#pragma once

#include "Console.hpp"
#include <fstream>

#define LINE (std::to_string(__LINE__) + "]")

class Log {
public:
	static void init(const std::string& logFileName);
	static void close();

	static void logError(const std::string& str);
	static void logStatus(const std::string& str);
	static void logStatus(const std::string& str, ConsoleColor color);

private:
	static const std::string getCurrentDateTime();
	static std::fstream logFile;
};