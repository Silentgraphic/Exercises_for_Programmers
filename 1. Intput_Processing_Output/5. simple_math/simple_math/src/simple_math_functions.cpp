#include "simple_math.h"

int convertStringToInt(std::string& valueToConvert)
{
	return std::stoi(valueToConvert);
}

std::string userPrompt(const std::string& prompt, std::istream& input, std::ostream& output)
{
	std::string userInput;
	output << prompt;
	input >> userInput;
	return userInput;
}