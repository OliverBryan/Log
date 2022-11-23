#include "Log.hpp"
#include <chrono>
#include <ctime>
#include <iostream>
#include <sstream>

std::fstream Log::logFile = std::fstream();

void Log::init(const std::string& logFileName) {
	logFile.open(logFileName, std::ios::out);
	if (!logFile) {
		throw std::runtime_error("Failed to open logfile");
	}

	logStatus("Initializing Log", ConsoleColor::LightGreen);
}

void Log::close() {
	logStatus("Closing Log", ConsoleColor::LightGreen);
	logFile.close();
}

void Log::logError(const std::string& str) {
	Console::changeColor(ConsoleColor::Red);
	Console::write(getCurrentDateTime() + str);
	Console::changeColor(Console::getPreviousColor());
	logFile << getCurrentDateTime() + str << std::endl;
}

void Log::logStatus(const std::string& str) {
	Console::write(getCurrentDateTime() + str);
	logFile << getCurrentDateTime() + str << std::endl;
}

void Log::logStatus(const std::string& str, ConsoleColor color) {
	Console::changeColor(color);
	Console::write(getCurrentDateTime() + str);
	Console::changeColor(Console::getPreviousColor());
	logFile << getCurrentDateTime() + str << std::endl;
}

const std::string Log::getCurrentDateTime() {
	time_t now = time(0);
	struct tm tstruct;
	char buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "[%Y-%m-%d.%X]: ", &tstruct);
	return buf;
}