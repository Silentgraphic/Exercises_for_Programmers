#include <iostream>
#include <vector>

#include "pch.h"
#include "USD.h"
#include "ICurrency.h"
#include "Item.h"

namespace USDTests {
	USD usdTest((long int)2);
	TEST(USDTest, ExpectConstructorToset) {
		EXPECT_EQ(2, usdTest.twoSignificantDigits);
	}
}

namespace ItemTests {
	class MockCurrency : public ICurrency {
	public:
		MockCurrency(const long int& priceInCents) : ICurrency(priceInCents) {};
		MOCK_METHOD(float, convertToDecimal, ());
	};

	TEST(ItemTests, TotalCalculatedIs2) {
		Item testItem;
		MockCurrency currency((long int)2);
		testItem.calculateTotal(currency, 1);
		EXPECT_EQ(2, testItem.total);
	}

	TEST(ItemTests, TotalCalculatedIs4) {
		Item testItem;
		MockCurrency currency((long int)2);
		testItem.calculateTotal(currency, 2);
		EXPECT_EQ(4, testItem.total);
	}
}