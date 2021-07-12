#pragma once

#include "ICurrency.h"

class USD : public ICurrency {
public:
	USD(const long int& priceInCents) :ICurrency(priceInCents) {};

	float convertToDecimal();
};