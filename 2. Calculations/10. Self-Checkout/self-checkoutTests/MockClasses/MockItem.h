#pragma once

#include "IItem.h"
#include "ICurrency.h"

class MockItem :public IItem {
public:
	MockItem() {};
	MockItem(ICurrency& price) {};
	//Only here cause I don't know to to set the total price when returning from MockDataManager
	MockItem(long int totalPriceForMockDataMangager) : totalPrice(totalPriceForMockDataMangager) {};
	MOCK_METHOD(void, calculateTotal, (int quantity));
	MOCK_METHOD(void, setCurrency, (ICurrency& price));
	int totalPrice = 0;
};