#include <string>

#include "pch.h"

#include "Euro.h"
#include "CurrencyConverter.h"

namespace EuroTests {
	TEST(EuroTests, ExpectConstructorTosetInt) {
		long int test = 2000;
		Euro euroTest(test);
		EXPECT_EQ(2000, euroTest.twoSignificantDigits);
	}
	TEST(EuroTests, ExpectConstructorTosetDouble) {
		long double test = 1.11;
		Euro euroTest(test);
		EXPECT_EQ(1110, euroTest.twoSignificantDigits);
	}
}