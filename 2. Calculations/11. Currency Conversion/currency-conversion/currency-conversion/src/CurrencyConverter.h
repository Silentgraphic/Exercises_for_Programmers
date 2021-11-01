#pragma once

#include "ICurrency.h"

class CurrencyConverter {
public:

	CurrencyConverter(ICurrency& currencyToConvert) :
		currencyToBeConverted(currencyToConvert) {};

	void setCurrency(ICurrency& currencyToConvert);

	long int convertToDollars();
	long int convertToEuros();
private:
	ICurrency& currencyToBeConverted;
};
