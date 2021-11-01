#include <string>

#include "pch.h"

#include "MockClasses/mockEuro.h"

#include "Euro.h"
#include "CurrencyConverter.h"
#include "ICurrency.h"

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

namespace CurrencyConverterTests {
	class currencyConverterTestEuros : public ::testing::Test {
		protected:
			void SetUp() override {
				euroTest_1.twoSignificantDigits = 1000;
				euroTest_2.twoSignificantDigits = 1500;
			}
			MockEuro euroTest_1;
			CurrencyConverter testCurrencyConverter_1 = CurrencyConverter(euroTest_1);
			MockEuro euroTest_2;
			CurrencyConverter testCurrencyConverter_2 = CurrencyConverter(euroTest_2);
	};
	TEST_F(currencyConverterTestEuros,WholeEurosConvertToEurosCorrectly) {
		euroTest_1.toEurosAsPercentage = 100;
		EXPECT_EQ(1000, testCurrencyConverter_1.convertToEuros());
	}

	TEST_F(currencyConverterTestEuros, FractionsOfEurosConvertToDollarsCorrectly_1) {
		euroTest_2.toDollarsAsPercentage = 200;
		EXPECT_EQ(3000, testCurrencyConverter_2.convertToDollars());
	}

	TEST_F(currencyConverterTestEuros, FractionsOfConvertToDollarsCorrectly_2) {
		euroTest_2.toDollarsAsPercentage = 300;
		EXPECT_EQ(4500, testCurrencyConverter_2.convertToDollars());
	}
}