#pragma once

#include "IItem.h"

class MockItem :public IItem {
public:
	MOCK_METHOD(void, calculateTotal, (int quantity));
	MOCK_METHOD(void, setCurrency, (ICurrency& price));
};