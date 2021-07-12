#include <iostream>
#include <vector>

#include "pch.h"
#include "USD.h"

namespace USDTests {
	USD usdTest((long int)2);
	TEST(USDTest, ExpectConstructorToset) {
		EXPECT_EQ(2, usdTest.twoSignificantDigits);
	}
}