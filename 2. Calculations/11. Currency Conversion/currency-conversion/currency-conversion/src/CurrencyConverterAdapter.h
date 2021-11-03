#pragma once

#include <memory>

#include "ICurrency.h"


class CurrencyConverterAdapter
{
public:
	std::unique_ptr<ICurrency> setValues();
private:

};
