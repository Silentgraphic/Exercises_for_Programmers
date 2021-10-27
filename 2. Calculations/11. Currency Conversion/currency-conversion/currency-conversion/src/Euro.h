#pragma once

#include<string>
#include <cmath>

#include "ICurrency.h"

struct Euro : public ICurrency {
	//If it is a decimal point then convert to whole number
	Euro(const long double& priceAsFloat) : ICurrency(0) {
		twoSignificantDigits = std::round(priceAsFloat * 1000);
	};
	//else just store it
	Euro(const long int& priceInCents) :ICurrency(priceInCents) {};

	std::string returnPresentableFormat();
};

std::string Euro::returnPresentableFormat() {
	return std::string();
}