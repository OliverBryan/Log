#pragma once

#include <string>
#include <windows.h>

enum class ConsoleColor {
	DarkBlue,
	Green,
	LightBlue,
	Red,
	Purple,
	Gold,
	White,
	Grey,
	Blue,
	LightGreen,
	NeonBlue,
	Pink,
	LightPurple,
	Yellow,
	BrightWhite
};

class Console {
public:
	//static void init();

	static void write(const std::string& str);
	static void changeColor(ConsoleColor color);
	static ConsoleColor getCurrentColor();
	static ConsoleColor getPreviousColor();

private:
	static ConsoleColor currentColor;
	static ConsoleColor previousColor;
	static HANDLE hConsole;
};