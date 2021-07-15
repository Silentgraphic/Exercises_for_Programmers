#pragma once

#include "ITaxCal.h"

class MockTaxCal :public ITaxCal {
public:
	MOCK_METHOD(unsigned long int, calculateTotalExTax, ());
	MOCK_METHOD(unsigned long int, calculateTotalIncTax, ());
};