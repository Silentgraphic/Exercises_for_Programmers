#pragma once
#include<string>
#include <cmath>

#include "ICurrency.h"

struct  USD : public ICurrency {
	USD(const long double& priceAsFloat) : ICurrency(0) {
		twoSignificantDigits = std::round(priceAsFloat * 1000);
	};
	USD(const long int& priceInCents) :ICurrency(priceInCents) {};

	std::string returnPresentableFormat();
};