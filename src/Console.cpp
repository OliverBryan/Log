#include "Console.hpp"
#include <iostream>

ConsoleColor Console::currentColor = ConsoleColor::White;
ConsoleColor Console::previousColor = ConsoleColor::White;
HANDLE Console::hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void Console::write(const std::string& str) {
	std::cout << str << std::endl;
}

void Console::changeColor(ConsoleColor color) {
	previousColor = currentColor;
	currentColor = color;
	SetConsoleTextAttribute(hConsole, static_cast<int>(currentColor) + 1);
}

ConsoleColor Console::getCurrentColor() {
	return currentColor;
}

ConsoleColor Console::getPreviousColor() {
	return previousColor;
}