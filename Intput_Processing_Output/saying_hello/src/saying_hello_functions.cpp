#include "saying_hello_header.h"
#include<stdexcept>

std::string concatString(std::string fullString, const std::string subString)
{
	const std::string marker = "*";
	rsize_t pos;

	pos = fullString.find(marker);
	if (pos == std::string::npos)
	{
		throw std::invalid_argument("No string markers found");
	}
	else
	{
		while (pos != std::string::npos)
		{
			fullString = fullString.replace(pos, 1, subString);
			pos = fullString.find(marker);
		};
	}
	return fullString;
}

std::string getConsoleInput(std::istream& input)
{
	std::string userInput;
	getline(input, userInput);
	return userInput;
}

void consoleOutput(std::ostream& output, std::string stringToBePrinted)
{
	output << stringToBePrinted;
}