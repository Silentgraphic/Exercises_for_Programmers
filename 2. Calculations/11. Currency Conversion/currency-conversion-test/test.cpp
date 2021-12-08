#include "pch.h"

#include <string>
#include <memory>

#include "MockClasses/mockEuro.h"
#include "MockClasses/MockUserInput.h"

#include "Euro.h"
#include "CurrencyConverter.h"
#include "ICurrency.h"
#include "CurrencyConverterAdapter.h"

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
	TEST_F(currencyConverterTestEuros,WholeEurosConvertToEurosCorrectlyWholePercent) {
		euroTest_1.toEurosAsPercentage = 100;
		EXPECT_EQ(1000, testCurrencyConverter_1.convertToEuros());
	}

	TEST_F(currencyConverterTestEuros, WholeEurosConvertToDollarsCorrectly_1) {
		euroTest_1.toDollarsAsPercentage = 100;
		EXPECT_EQ(1000, testCurrencyConverter_1.convertToDollars());
	}

	TEST_F(currencyConverterTestEuros, WholeEurosConvertToDollarsCorrectly_2) {
		euroTest_1.toDollarsAsPercentage = 100.5;
		EXPECT_EQ(1005, testCurrencyConverter_1.convertToDollars());
	}

	TEST_F(currencyConverterTestEuros, WholeEurosConvertToDollarsCorrectly_3) {
		euroTest_1.toDollarsAsPercentage = 90;
		EXPECT_EQ(900, testCurrencyConverter_1.convertToDollars());
	}

	TEST_F(currencyConverterTestEuros, FractionsOfEurosConvertToDollarsCorrectly_1) {
		euroTest_2.toDollarsAsPercentage = 100;
		EXPECT_EQ(1500, testCurrencyConverter_2.convertToDollars());
	}

	TEST_F(currencyConverterTestEuros, FractionsOfConvertToDollarsCorrectly_2) {
		euroTest_2.toDollarsAsPercentage = 100.5;
		EXPECT_EQ(1507, testCurrencyConverter_2.convertToDollars());
	}
}

namespace CurrencyConverterAdapterTests {
	class CurrencyConverterAdapterTests : public::testing::Test {
	protected:
		MockUserInput mockUserInput;
		std::stringstream mockStreamInt;
		CurrencyConverterAdapter CurrencyConverterAdapterTest = CurrencyConverterAdapter(mockUserInput);

		void SetUp() override {
			mockStreamInt << "1000" << std::endl;
		}
	};

	TEST_F(CurrencyConverterAdapterTests, CallsForUserInput) {
		EXPECT_CALL(mockUserInput, promptUser)
			.WillRepeatedly(testing::ReturnRef(mockStreamInt));
		auto returnedEuro = std::make_shared<MockEuro>();
		CurrencyConverterAdapterTest.setValues(returnedEuro);
	}

	TEST_F(CurrencyConverterAdapterTests, SetsValueOfEuro) {
		ON_CALL(mockUserInput, promptUser)
			.WillByDefault(testing::ReturnRef(mockStreamInt));

		auto returnedEuro = std::make_shared<MockEuro>();
		CurrencyConverterAdapterTest.setValues(returnedEuro);

		EXPECT_EQ(returnedEuro->twoSignificantDigits, 1000);
	}
}