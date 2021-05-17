#include <iostream>
#include <string>
#include <sstream>
#include "saying_hello_header.h"

int main()
{
	consoleOutput(std::cout, "Enter name:");
	std::string name = getConsoleInput(std::cin);
	std::string outputSentance = concatString("Hello, *, nice to meet you!", name);
	consoleOutput(std::cout, outputSentance);
	getConsoleInput(std::cin);
}