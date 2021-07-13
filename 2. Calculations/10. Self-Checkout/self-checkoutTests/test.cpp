#include <iostream>
#include <vector>

#include "pch.h"
#include "USD.h"
#include "Item.h"
#include "TaxCal.h"

#include "MockClasses/MockCurrency.h"
#include "MockClasses/MockItem.h"

namespace USDTests {
	USD usdTest(2000);
	TEST(USDTest, ExpectConstructorToset) {
		EXPECT_EQ(2000, usdTest.twoSignificantDigits);
	}
}

namespace ItemTests {
	TEST(ItemTests, TotalCalculatedIs2) {
		MockCurrency currency(2000);
		Item testItem(currency);
		testItem.calculateTotal(1);
		EXPECT_EQ(2000, testItem.totalPrice);
	}

	TEST(ItemTests, TotalCalculatedIs4) {
		MockCurrency currency(2000);
		Item testItem(currency);
		testItem.calculateTotal(2);
		EXPECT_EQ(4000, testItem.totalPrice);
	}
}

namespace TaxCalTests {
	class  TaxCalTest : public ::testing::Test {
	protected:
		void SetUp() override {
			MockItem item1;
			MockItem item2;
			MockItem item3;
			item1.totalPrice = 1000;
			item2.totalPrice = 1000;
			item3.totalPrice = 1000;
			mockItems.push_back(&item1);
			mockItems.push_back(&item2);
			mockItems.push_back(&item3);
		}
		void TearDown() override {
			mockItems.clear();
		}
		std::vector<IItem*> mockItems;
	};

	TEST_F(TaxCalTest, CorrectTotalExTax) {
		TaxCal testTaxCal(mockItems);
		long int totalExTax = testTaxCal.calculateTotalExTax();
		EXPECT_EQ(3000, totalExTax);
	}
	TEST_F(TaxCalTest, CorrectTotalIncTax) {
		TaxCal testTaxCal(mockItems);
		long int totalIncTax = testTaxCal.calculateTotalIncTax();
		EXPECT_EQ(3165, totalIncTax);
	}
}