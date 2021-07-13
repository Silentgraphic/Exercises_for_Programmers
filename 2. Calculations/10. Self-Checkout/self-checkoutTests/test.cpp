#include <iostream>
#include <vector>

#include "pch.h"
#include "USD.h"
#include "Item.h"

#include "MockClasses/MockCurrency.h"

namespace USDTests {
	USD usdTest((long int)2);
	TEST(USDTest, ExpectConstructorToset) {
		EXPECT_EQ(2, usdTest.twoSignificantDigits);
	}
}

namespace ItemTests {
	TEST(ItemTests, TotalCalculatedIs2) {
		MockCurrency currency((long int)2);
		Item testItem(currency);
		testItem.calculateTotal(1);
		EXPECT_EQ(2, testItem.total);
	}

	TEST(ItemTests, TotalCalculatedIs4) {
		MockCurrency currency((long int)2);
		Item testItem(currency);
		testItem.calculateTotal(2);
		EXPECT_EQ(4, testItem.total);
	}
}