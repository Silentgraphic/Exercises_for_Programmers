#pragma once
#include <string>
#include <sstream>
#include <cmath>
#include <iostream>

#include "IUserInput.h"
#include "IValidateInput.h"

class UserInput : public IUserInput {
public:
	UserInput(std::istream& input, std::ostream& output, IValidateInput& inputValidator) :
		inputStream(input),
		outputStream(output),
		inputValidator(inputValidator) {
	};
	std::stringstream& promptUser(std::string prompt);
private:
	std::istream& inputStream;
	std::ostream& outputStream;
	IValidateInput& inputValidator;
	std::stringstream validatedInput;
	void getValidatedUserInput();
};
