#include <iostream>
#include <string>
#include "simple_math.h"
#include "simple_math_class.h"
#include "user_ouput.h"

int main()
{
	//This is a bit of a mess but its what the Constraints wanted
	const std::string firstPrompt = "What Is first Number:";
	const std::string secondPrompt = "what is second number:";
	std::string userInputNumberOne = userPrompt(firstPrompt, std::cin, std::cout);
	std::string userInputNumberTwo = userPrompt(secondPrompt, std::cin, std::cout);
	int numberOne = convertStringToInt(userInputNumberOne);
	int numberTwo = convertStringToInt(userInputNumberTwo);
	SimpleMath simpleMathObject(numberOne, numberTwo);
	UserOuput userOutput(simpleMathObject);
	userOutput.printUserOutput(std::cout);
}