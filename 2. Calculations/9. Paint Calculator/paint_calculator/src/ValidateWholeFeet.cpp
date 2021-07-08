#include "ValidateWholeFeet.h"
#include <cmath>

void ValidateWholeFeet::ValidateInput(std::string stringInput) {
	float userInput;
	std::stringstream myStream(stringInput);
	myStream >> userInput;
	if (myStream.fail()) {
		throw std::runtime_error("Invalid please enter number: ");
	} else if (std::floor(userInput) != userInput) {
		throw std::runtime_error("Invalid please enter a whole foot: ");
	}
}