#include "ValidatePrice.h"
#include <cmath>

void ValidatePrice::ValidateInput(const std::string& stringInput) {
	float userInput;
	std::stringstream myStream(stringInput);
	myStream >> userInput;
	if (myStream.fail()) {
		throw std::runtime_error("Invalid please enter number: ");
	}
}