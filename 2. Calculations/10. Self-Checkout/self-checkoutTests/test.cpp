#include <iostream>
#include <vector>

#include "pch.h"
#include "USD.h"
#include "Item.h"
#include "TaxCal.h"
#include "ITaxCal.h"
#include "DataManager.h"

#include "MockClasses/MockCurrency.h"
#include "MockClasses/MockItem.h"
#include "MockClasses/MockTaxCal.h"

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
			mockItems.push_back(&item1);
			mockItems.push_back(&item2);
			mockItems.push_back(&item3);
			mockItems.at(0)->totalPrice = 1000;
			mockItems.at(1)->totalPrice = 1000;
			mockItems.at(2)->totalPrice = 1000;
		}
		void TearDown() override {
			mockItems.clear();
		}
		std::vector<IItem*> mockItems;
		MockItem item1;
		MockItem item2;
		MockItem item3;
	};

	TEST_F(TaxCalTest, CorrectTotalExTax) {
		TaxCal testTaxCal(mockItems);
		long int totalExTax = testTaxCal.calculateTotalExTax();
		EXPECT_EQ(3000, totalExTax);
	}
	TEST_F(TaxCalTest, CorrectTotalIncTax) {
		TaxCal testTaxCal(mockItems);
		long int totalIncTax = testTaxCal.calculateTotalIncTax();
		EXPECT_EQ(3170, totalIncTax);
	}
}

namespace DataManagerTests {
	class  DataManagerTest : public ::testing::Test {
	protected:
		MockTaxCal taxCal;
		DataManager<MockCurrency> dataMananger;
	};

	TEST_F(DataManagerTest, GetItemsReturnsVectorOfPointers) {
		dataMananger.getItems<MockItem>();
		for (auto& itemPtr : dataMananger.items) {
			EXPECT_NE(itemPtr, nullptr);
		}
	}

	TEST_F(DataManagerTest, ExpectEachItemToHaveCallCalculateTotal) {
		//Add at least 3 items so I have something to test on
		dataMananger.getItems<MockItem>();
		//Get pointer to a mock obeject
		MockItem* mockItem = dynamic_cast<MockItem*>(dataMananger.items[0]);
		EXPECT_CALL(*mockItem, calculateTotal)
			.Times(testing::AtLeast(1));
		dataMananger.getItems<MockItem>();
	}
}