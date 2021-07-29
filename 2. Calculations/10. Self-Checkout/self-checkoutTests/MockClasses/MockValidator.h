#pragma once

#include "IValidateInput.h"

class MockValidator : public IValidateInput {
public:
	MOCK_METHOD(void, ValidateInput, (const std::string& stringInput));
};