#include "user_ouput.h"
#include <iostream>

void UserOuput::printUserOutput(std::ostream& output)
{
	output << simpleMathObject.getFirstNumber() << "+" << simpleMathObject.getSecondNumber() << "=" << simpleMathObject.addition() << "\n"
		<< simpleMathObject.getFirstNumber() << "-" << simpleMathObject.getSecondNumber() << "=" << simpleMathObject.subtraction() << "\n"
		<< simpleMathObject.getFirstNumber() << "*" << simpleMathObject.getSecondNumber() << "=" << simpleMathObject.multiply() << "\n"
		<< simpleMathObject.getFirstNumber() << "/" << simpleMathObject.getSecondNumber() << "=" << simpleMathObject.division() << "\n";
}