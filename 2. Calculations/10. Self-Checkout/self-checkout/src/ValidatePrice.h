#pragma once
#include "IValidateInput.h"
#include <string>
#include <sstream>

class ValidatePrice : public IValidateInput {
public:
	void ValidateInput(const std::string& stringInput);
};
