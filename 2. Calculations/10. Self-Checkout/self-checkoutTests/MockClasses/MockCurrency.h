#pragma once

#include "ICurrency.h"

struct MockCurrency : public ICurrency {
public:
	MockCurrency(const long int& priceInCents) : ICurrency(priceInCents) {};
	MOCK_METHOD(std::string, returnPresentableFormat, ());
};