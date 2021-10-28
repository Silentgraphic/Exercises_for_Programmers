#pragma once

#include "ICurrency.h"
#include <string>

struct MockEuro : public ICurrency {
public:

	long int toDollars = 0;

	MockEuro(const long int& value) : ICurrency(value) {};
	MOCK_METHOD(std::string, returnPresentableFormat, ());
};