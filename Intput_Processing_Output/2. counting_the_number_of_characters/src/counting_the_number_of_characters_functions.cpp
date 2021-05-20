#include <string>
#include <sstream>

std::string getUserString(std::istream& input, std::ostream& output)
{
	output << "What is the input string: ";
	std::string userInput;
	getline(input, userInput);
	return userInput;
}