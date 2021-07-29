#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "pch.h"
#include "USD.h"
#include "Item.h"
#include "TaxCal.h"
#include "DataManager.h"
#include "User_prompt.h"

#include "MockClasses/MockCurrency.h"
#include "MockClasses/MockItem.h"
#include "MockClasses/MockDataManager.h"
#include "MockClasses/MockUserInput.h"
#include "MockClasses/MockValidator.h"

namespace USDTests {
	TEST(USDTest, ExpectConstructorTosetInt) {
		long int test = 2000;
		USD usdTest(test);
		EXPECT_EQ(2000, usdTest.twoSignificantDigits);
	}
	TEST(USDTest, ExpectConstructorTosetDouble) {
		long double test = 1.11;
		USD usdTest(test);
		EXPECT_EQ(1110, usdTest.twoSignificantDigits);
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
		MockDataManager mockDataManger;
	};

	TEST_F(TaxCalTest, GetItemsCalledAtLeast3Times) {
		TaxCal testTaxCal(mockDataManger);

		EXPECT_CALL(mockDataManger, getItems)
			.Times(testing::AtLeast(3))
			.WillRepeatedly([]() {
			std::unique_ptr<IItem> item = std::unique_ptr<IItem>(new MockItem);
			item->totalPrice = 1000;
			return item;
		});
		testTaxCal.calculateTotalExTax();
	};

	TEST_F(TaxCalTest, CorrectTotalExTax) {
		TaxCal testTaxCal(mockDataManger);

		EXPECT_CALL(mockDataManger, getItems)
			.WillRepeatedly([]() {
			std::unique_ptr<IItem> item = std::unique_ptr<IItem>(new MockItem);
			item->totalPrice = 1000;
			return item;
		});

		long int totalExTax = testTaxCal.calculateTotalExTax();
		EXPECT_EQ(3000, totalExTax);
	}
	TEST_F(TaxCalTest, CorrectTotalIncTax) {
		TaxCal testTaxCal(mockDataManger);

		EXPECT_CALL(mockDataManger, getItems)
			.WillRepeatedly([]() {
			std::unique_ptr<IItem> item = std::unique_ptr<IItem>(new MockItem);
			item->totalPrice = 1000;
			return item;
		});

		long int totalIncTax = testTaxCal.calculateTotalIncTax();
		EXPECT_EQ(3170, totalIncTax);
	}
}

namespace DataManagerTests {
	MockUserInput mockUserInputFloat;
	MockUserInput mockUserInputInt;
	DataManager dataMananger(mockUserInputFloat, mockUserInputInt);
	class  DataManagerTest : public ::testing::Test {
	public:
		std::stringstream mockStreamFloat;
		std::stringstream mockStreamInt;
		void SetUp() override {
			mockStreamFloat << "1.0" << std::endl;
			mockStreamInt << "1" << std::endl;
		}
	};

	TEST_F(DataManagerTest, FetItemReturnsTypeOfIItem) {
		EXPECT_CALL(mockUserInputFloat, promptUser)
			.WillRepeatedly(testing::ReturnRef(mockStreamFloat));
		EXPECT_CALL(mockUserInputInt, promptUser)
			.WillRepeatedly(testing::ReturnRef(mockStreamInt));
		auto returnedItem = dataMananger.getItems();
		EXPECT_NE(nullptr, returnedItem);
	}

	TEST_F(DataManagerTest, ReturnedItemToHaveATotalPrice) {
		EXPECT_CALL(mockUserInputFloat, promptUser)
			.WillRepeatedly(testing::ReturnRef(mockStreamFloat));
		EXPECT_CALL(mockUserInputInt, promptUser)
			.WillRepeatedly(testing::ReturnRef(mockStreamInt));
		auto returnedItemPtr = dataMananger.getItems();

		EXPECT_NE(NULL, returnedItemPtr->totalPrice);
	}
	TEST_F(DataManagerTest, ExepctTotalPriceToBe1000) {
		EXPECT_CALL(mockUserInputFloat, promptUser)
			.WillRepeatedly(testing::ReturnRef(mockStreamFloat));
		EXPECT_CALL(mockUserInputInt, promptUser)
			.WillRepeatedly(testing::ReturnRef(mockStreamInt));
		auto returnedItemPtr = std::move(dataMananger.getItems());
		EXPECT_EQ(1000, returnedItemPtr->totalPrice);
	}
	TEST_F(DataManagerTest, ExpectPromptUserToBeCalledAtLeastOnceForIntAndFloat) {
		EXPECT_CALL(mockUserInputFloat, promptUser)
			.Times(testing::AtLeast(1))
			.WillRepeatedly(testing::ReturnRef(mockStreamFloat));
		EXPECT_CALL(mockUserInputInt, promptUser)
			.WillRepeatedly(testing::ReturnRef(mockStreamInt));
	}
}

namespace GetUserIntput {
	class  GetUserInputTest : public ::testing::Test {
	protected:
		void SetUp() override {
		}
		void TearDown() override {
			fakeInput.str("");
			fakeInput.clear();
			output.str("");
			output.clear();
		}
		UserInput testUserInput = UserInput(fakeInput, output, mockValidator);
		MockValidator mockValidator;
		std::stringstream fakeInput;
		std::stringstream output;
	};
	TEST_F(GetUserInputTest, PrintsErrorWIthInvalidInput) {
		EXPECT_CALL(mockValidator, ValidateInput)
			.WillRepeatedly(testing::Throw(std::runtime_error("Err")));

		testUserInput.promptUser("");

		EXPECT_EQ("Err", output.str());
	}
	TEST_F(GetUserInputTest, ExpectAPromtForUser) {
		const std::string prompt = "What is foo?\n";

		fakeInput << std::endl;

		testUserInput.promptUser(prompt);

		EXPECT_EQ(prompt, output.str());
	}
	TEST_F(GetUserInputTest, ReturnsInt) {
		fakeInput << "1";

		long double outputAsInt = 0;
		testUserInput.promptUser("") >> outputAsInt;

		EXPECT_EQ(outputAsInt, 1);
	}

	TEST_F(GetUserInputTest, ReturnsDouble) {
		fakeInput << "1.1";

		long double outputAsDouble = 0;
		testUserInput.promptUser("") >> outputAsDouble;

		EXPECT_EQ(outputAsDouble, 1.1);
	}
}