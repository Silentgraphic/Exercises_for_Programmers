#pragma once
#include <string>
class IValidateInput {
public:
	virtual void ValidateInput(const std::string& stringInput) = 0;
};