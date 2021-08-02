#pragma once
#include "IValidateInput.h"
#include <string>
#include <sstream>

class ValidateWholeNumber : public IValidateInput {
public:
	void ValidateInput(const std::string& stringInput);
};
