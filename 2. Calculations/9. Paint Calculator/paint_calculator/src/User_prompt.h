#pragma once
#include <string>
#include <sstream>
#include <cmath>
#include "User_prompt_base.h"
#include "IValidateInput.h"

template <typename T>
class UserInput : public UserInputBase
{
public:
	UserInput(std::istream& input, std::ostream& output, IValidateInput& inputValidator) :
		UserInputBase(input, output),
		inputStream(input),
		outputStream(output),
		inputValidator(inputValidator)
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
	IValidateInput& inputValidator;
	T getValidatedUserInput()
	{
		std::string strInput = "";
		T userInput;
		do
		{
			std::getline(inputStream, strInput);
			try
			{
				inputValidator.ValidateInput(strInput);
				break;
			}
			catch (std::runtime_error& err)
			{
				outputStream << err.what();
			}
		} while (true);
		std::stringstream myStream(strInput);
		myStream >> userInput;
		return userInput;
	};
};