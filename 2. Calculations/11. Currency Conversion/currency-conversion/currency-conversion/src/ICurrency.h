#pragma once
#include <string>

struct ICurrency {
	//Force all ICurrency inplemtations to have a value
	ICurrency(const long int& currencyAsLongInt) :
		twoSignificantDigits(currencyAsLongInt) {
	};
	long int twoSignificantDigits;
	virtual std::string returnPresentableFormat() = 0;

	//Conversion rates
	long double toDollars = 0;
	long double toEuros = 0;
};
