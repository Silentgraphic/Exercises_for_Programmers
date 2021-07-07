#pragma once
#include "IValidateInput.h"
#include <string>
#include <sstream>

class ValidateFloat : public IValidateInput
{
public:
	void ValidateInput(std::string stringInput);
};
