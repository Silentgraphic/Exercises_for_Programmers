#pragma once

class ICurrency {
public:
	//Force all ICurrency inplemtations to have a value
	ICurrency(const long int& currencyAsLongInt) :
		twoSignificantDigits(currencyAsLongInt) {
	};
	long int twoSignificantDigits;
	virtual float convertToDecimal() = 0;
};
