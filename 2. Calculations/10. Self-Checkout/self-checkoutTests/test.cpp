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
#include "ValidateWholeNumber.h"
#include "ValidatePrice.h"
#include "String_interpolation.h"
#include "SelfCheckoutOutput.h"

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
			.WillOnce(testing::Throw(std::runtime_error("Err")))
			.WillOnce(testing::Return());

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

namespace ValidatorWholeNumber {
	ValidateWholeNumber validateTest;
	const std::string testString = "foo";
	const std::string wholeNumber = "1";
	const std::string decimalNumber = "1.1";
	TEST(ValidateWholeNumber, DoesNotThrowException) {
		EXPECT_NO_THROW(validateTest.ValidateInput(wholeNumber));
	}
	TEST(ValidateWholeNumber, DoesThrowExceptionForString) {
		EXPECT_ANY_THROW(validateTest.ValidateInput(testString));
	}
	TEST(ValidateWholeNumber, DoesThrowExceptionForDecimalPlace) {
		EXPECT_ANY_THROW(validateTest.ValidateInput(decimalNumber));
	}
	TEST(ValidateWholeNumber, ThrowsInvalidForString) {
		try {
			validateTest.ValidateInput(testString);
		}
		catch (std::runtime_error& err) {
			const std::string expectedString = "Invalid please enter number: ";
			EXPECT_EQ(expectedString, err.what());
		}
	}
	TEST(ValidateWholeNumber, ThrowsInvalidDecimalPlace) {
		try {
			validateTest.ValidateInput(decimalNumber);
		}
		catch (std::runtime_error& err) {
			const std::string expectedString = "Invalid please enter correct quantity: ";
			EXPECT_EQ(expectedString, err.what());
		}
	}
}

namespace ValidatorWPrice {
	ValidatePrice validateTest;
	const std::string testString = "foo";
	const std::string wholeNumber = "1";
	const std::string decimalNumber = "1.1";
	TEST(ValidatePrice, DoesNotThrowException) {
		EXPECT_NO_THROW(validateTest.ValidateInput(wholeNumber));
	}
	TEST(ValidatePrice, DoesThrowExceptionForString) {
		EXPECT_ANY_THROW(validateTest.ValidateInput(testString));
	}
	TEST(ValidatePrice, DoesNotThrowExceptionForDecimalPlace) {
		EXPECT_NO_THROW(validateTest.ValidateInput(decimalNumber));
	}
	TEST(ValidatePrice, ThrowsInvalidForString) {
		try {
			validateTest.ValidateInput(testString);
		}
		catch (std::runtime_error& err) {
			const std::string expectedString = "Invalid please enter number: ";
			EXPECT_EQ(expectedString, err.what());
		}
	}
}

namespace StringInterpolation {
	const std::map<std::string, std::string> testSubStrings = { {"foo" , "Foo"},{"bar", "Bar"} };
	const std::map<std::string, int> testSubInt = { {"foo" , 1},{"bar", 2} };
	std::string testSingleMarkerString = "What is {foo}?";
	std::string testDoubleMarkerString = "What is {foo} {bar}?";
	StringInter testStringInterpolation;

	TEST(StringInterpolation, NoMarkerInFullString) {
		std::string testStringNoMarker = "What is ?";

		EXPECT_THROW(testStringInterpolation.interpolateString<std::string>(testStringNoMarker, testSubStrings), std::invalid_argument);
	}

	TEST(StringInterpolation, ReturnsStringWithSingleStringInput) {
		const std::string expectedString = "What is Foo?";

		std::string returnedString = testStringInterpolation.interpolateString<std::string>(testSingleMarkerString, testSubStrings);

		EXPECT_EQ(expectedString, returnedString);
	}

	TEST(StringInterpolation, ReturnsStringWithMultipleStringInput) {
		const std::string expectedString = "What is Foo Bar?";

		std::string returnedString = testStringInterpolation.interpolateString<std::string>(testDoubleMarkerString, testSubStrings);

		EXPECT_EQ(expectedString, returnedString);
	}

	TEST(StringInterpolation, ReturnsStringWithSingleIntInput) {
		const std::string expectedString = "What is 1?";

		std::string returnedString = testStringInterpolation.interpolateString<int>(testSingleMarkerString, testSubInt);

		EXPECT_EQ(expectedString, returnedString);
	}

	TEST(StringInterpolation, ReturnsStringWithMultipleIntInput) {
		const std::string expectedString = "What is 1 2?";

		std::string returnedString = testStringInterpolation.interpolateString<int>(testDoubleMarkerString, testSubInt);

		EXPECT_EQ(expectedString, returnedString);
	}
}

namespace selfCheckoutOutputTests {
	class  selfCheckoutOutputTest : public ::testing::Test {
	public:
		void SetUp() override {
			substrings.insert(std::pair("foo", 1000));
		}

		void TearDown() override {
			substrings.clear();
			output.str("");
			output.clear();
		}
		std::map<std::string, long double> substrings;
		std::stringstream output;
		SelfCheckoutOutput outPutTest = SelfCheckoutOutput(output);
	};

	TEST_F(selfCheckoutOutputTest, PrintsCorrectOutput) {
		outPutTest.printOutput(substrings, "test is {foo}");
		EXPECT_EQ("test is 1\n", output.str());
	}
}