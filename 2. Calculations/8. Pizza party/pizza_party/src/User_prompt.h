#pragma once
#include <string>
#include <sstream>
#include "User_prompt_base.h"

template <typename T>
class UserInput : public UserInputBase
{
public:
	UserInput(std::istream& input, std::ostream& output) :
		UserInputBase(input, output),
		inputStream(input),
		outputStream(output)
	{
	};

	T promptUser(std::string prompt)
	{
		T userInput;
		outputStream << prompt;
		userInput = getValidatedUserInput();
		return userInput;
	};
private:
	std::istream& inputStream;
	std::ostream& outputStream;
	std::string invalidInputMessage = "Invalid:";
	T getValidatedUserInput()
	{
		std::string strInput = "";
		T userInput;
		do
		{
			std::getline(inputStream, strInput);
			std::stringstream myStream(strInput);
			if ((myStream >> userInput))
			{
				break;
			}
			outputStream << invalidInputMessage;
		} while (true);
		return userInput;
	};
};