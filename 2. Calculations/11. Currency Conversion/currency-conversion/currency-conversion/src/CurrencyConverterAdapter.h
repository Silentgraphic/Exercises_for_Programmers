#pragma once

#include <memory>

#include "ICurrency.h"
#include "IUserInput.h"


class CurrencyConverterAdapter
{
public:
	CurrencyConverterAdapter(IUserInput& userInput):
		userInput(userInput){};
	void setValues(std::shared_ptr<ICurrency> currency);
private:
	long int euros;
	long double percentage;
	std::stringstream input;
	IUserInput& userInput;
};
