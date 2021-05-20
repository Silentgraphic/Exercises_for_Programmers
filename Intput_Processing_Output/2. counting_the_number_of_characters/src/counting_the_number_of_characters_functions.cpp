#include <string>
#include <sstream>

std::string getConsoleInput(std::istream& input)
{
	std::string userInput;
	getline(input, userInput);
	return userInput;
}