#pragma once
#include "IValidateInput.h"
#include <string>
#include <sstream>

class ValidateWholeFeet : public IValidateInput {
public:
	void ValidateInput(const std::string& stringInput);
};
