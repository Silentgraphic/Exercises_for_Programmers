#include "printing_quotes.h"

void setEscapedOutput(std::string& name, std::string& quote, std::ostream& output)
{
	output << name + " says " + char(34) + quote + char(34);
}

std::string getUserString(std::string& prompt, std::istream& input, std::ostream& output)
{
	output << prompt;
	std::string userInput;
	getline(input, userInput);
	return userInput;
}