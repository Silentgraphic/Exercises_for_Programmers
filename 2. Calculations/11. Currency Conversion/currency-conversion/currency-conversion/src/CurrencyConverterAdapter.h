#pragma once

#include <memory>

#include "ICurrency.h"
#include "IUserInput.h"


class CurrencyConverterAdapter
{
public:
	CurrencyConverterAdapter(IUserInput& userInput):
		userInput(userInput){};
	std::unique_ptr<ICurrency> setValues();
private:
	IUserInput& userInput;
};
