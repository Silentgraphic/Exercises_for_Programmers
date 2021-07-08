#include "pch.h"

#include <string>

#include"PaintPerAreaCalculator.h"
#include "Rectangle.h"
#include "User_prompt.h"
#include "ValidateWholeFeet.h"

namespace PaintPerAreaCalculatorClass {
	class  PaintPerAreaCalculatorTest : public ::testing::Test {
	protected:
		void SetUp() override {
			paint1_.setAreaInFeet(360.0);
		}

		PaintPerAreaCalculator paint1_;
		PaintPerAreaCalculator paint2_;
	};

	TEST_F(PaintPerAreaCalculatorTest, ExpectErrorWithNoArea) {
		EXPECT_ANY_THROW(paint2_.calculateGallons());
	}
	TEST_F(PaintPerAreaCalculatorTest, Expect2Gallons) {
		paint1_.calculateGallons();
		EXPECT_EQ(paint1_.getGallonsNeeded(), 2);
	}
}

namespace RectangleObject {
	TEST(RectangleObject, CalculateAreaMethod) {
		Rectangle testRectangle;

		float testLength = 23.0;
		float testWidth = 12.0;

		testRectangle.setLength(testLength);
		testRectangle.setWidth(testWidth);

		EXPECT_EQ(testRectangle.calculateArea(), 276);
	}
};

namespace ValidateWholeFoot {
	ValidateWholeFeet validateTest;
	const std::string testString = "foo";
	const std::string wholeNumber = "1";
	const std::string decimalNumber = "1.1";
	TEST(ValidateWholeFoot, DoesNotThrowException) {
		EXPECT_NO_THROW(validateTest.ValidateInput(wholeNumber));
	}
	TEST(ValidateWholeFoot, DoesThrowExceptionForString) {
		EXPECT_ANY_THROW(validateTest.ValidateInput(testString));
	}
	TEST(ValidateWholeFoot, DoesThrowExceptionForDecimalPlace) {
		EXPECT_ANY_THROW(validateTest.ValidateInput(decimalNumber));
	}
	TEST(ValidateWholeFoot, ThrowsInvalidForString) {
		try {
			validateTest.ValidateInput(testString);
		}
		catch (std::runtime_error& err) {
			const std::string expectedString = "Invalid please enter number: ";
			EXPECT_EQ(expectedString, err.what());
		}
	}
	TEST(ValidateWholeFoot, ThrowsInvalidDecimalPlace) {
		try {
			validateTest.ValidateInput(decimalNumber);
		}
		catch (std::runtime_error& err) {
			const std::string expectedString = "Invalid please enter a whole foot: ";
			EXPECT_EQ(expectedString, err.what());
		}
	}
}

namespace GetUserIntput {
	ValidateWholeFeet validateWholeFeet;
	std::stringstream fakeInput;
	std::stringstream output;
	UserInput<std::string> testUserInput(fakeInput, output, validateWholeFeet);

	class  GetUserInputTest : public ::testing::Test {
	protected:
		void TearDown() override {
			fakeInput.str("");
			fakeInput.clear();
			output.str("");
			output.clear();
		}
	};
	TEST_F(GetUserInputTest, ReturnsInvalidforString) {
		const std::string testString = "Foo";

		fakeInput << testString << std::endl << 1;

		testUserInput.promptUser("");

		EXPECT_EQ("Invalid please enter number: ", output.str());
	}
	TEST_F(GetUserInputTest, ReturnsInvalidForWholeNum) {
		const float testFloat = 1.1;

		fakeInput << testFloat << std::endl << 1;

		testUserInput.promptUser("");

		EXPECT_EQ("Invalid please enter a whole foot: ", output.str());
	}
	TEST_F(GetUserInputTest, ExpectAPromtForUser) {
		const std::string prompt = "What is foo?\n";

		fakeInput << "1";

		testUserInput.promptUser(prompt);

		EXPECT_EQ(prompt, output.str());
	}
	TEST_F(GetUserInputTest, ReturnsInputString) {
		fakeInput << "1";

		std::string returnedString = testUserInput.promptUser("");
		std::string returnedWholeNumberAsString = "1";

		EXPECT_EQ(returnedString, returnedWholeNumberAsString);
	}
}