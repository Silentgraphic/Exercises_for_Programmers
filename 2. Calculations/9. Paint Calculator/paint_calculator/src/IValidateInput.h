#pragma once
#include <string>
class IValidateInput {
public:
	virtual void ValidateInput(std::string stringInput) = 0;
};