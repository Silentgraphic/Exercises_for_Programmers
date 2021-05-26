#include "mad_lib.h"

void userPrompt(std::string(&words)[4][2], std::istream& input, std::ostream& output)
{
	for (auto& i : words)
	{
		std::string userInput;
		output << "Enter a " << i[0] << ":";
		input >> userInput;
		i[1] = userInput;
	}
}