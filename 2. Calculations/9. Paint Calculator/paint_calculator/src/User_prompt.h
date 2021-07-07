#pragma once
#include <string>
#include <sstream>
#include <cmath>
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
	T getValidatedUserInput()
	{
		std::string strInput = "";
		T userInput;
		do
		{
			std::getline(inputStream, strInput);
			try
			{
				userInput = validateInput(strInput);
				break;
			}
			catch (std::runtime_error& err)
			{
				outputStream << err.what();
			}
		} while (true);

		return userInput;
	};
	T validateInput(std::string stringInput)
	{
		T userInput;
		std::stringstream myStream(stringInput);
		if ((myStream >> userInput))
		{
			return userInput;
		}
		else
		{
			throw std::runtime_error("Invalid please enter a whole foot: ");
		}
	}
};