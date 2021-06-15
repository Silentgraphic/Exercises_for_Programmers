#include "userPrompt.h"
#include <sstream>

std::string userPrompt(const std::string& prompt, std::istream& input, std::ostream& output)
{
	std::string userInput;
	output << prompt;
	input >> userInput;
	return userInput;
}