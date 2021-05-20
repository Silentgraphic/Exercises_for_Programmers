#include <string>
#include <sstream>
#include "counting_the_number_of_characters.h"

std::string getUserString(std::istream& input, std::ostream& output)
{
	output << "What is the input string: ";
	std::string userInput;
	getline(input, userInput);
	return userInput;
}

void charCountOutput(std::string fullString, int charCount, std::ostream& output)
{
}