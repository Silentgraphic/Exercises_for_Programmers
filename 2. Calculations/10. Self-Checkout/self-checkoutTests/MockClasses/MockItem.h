#pragma once

#include "IItem.h"
#include "ICurrency.h"

class MockItem :public IItem {
public:
	MockItem() {};
	MockItem(ICurrency& price) {};
	MOCK_METHOD(void, calculateTotal, (int quantity));
	MOCK_METHOD(void, setCurrency, (ICurrency& price));
};