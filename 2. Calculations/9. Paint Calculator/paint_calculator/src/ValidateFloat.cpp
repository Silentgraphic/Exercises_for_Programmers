#include "ValidateFloat.h"

void ValidateFloat::ValidateInput(std::string stringInput)
{
	float userInput;
	std::stringstream myStream(stringInput);
	myStream >> userInput;
	if (myStream.fail())
	{
		throw std::runtime_error("Invalid please enter a whole foot: ");
	}
}