#pragma once

#include "ICurrency.h"
#include <string>

struct MockEuro : public ICurrency {
public:
	MockEuro() : ICurrency(0) {};
	MOCK_METHOD(std::string, returnPresentableFormat, ());
};