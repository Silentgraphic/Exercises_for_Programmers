#include "pch.h"

#include <string>

#include"PaintPerAreaCalculator.h"
#include "Rectangle.h"
#include "User_prompt.h"
#include "ValidateWholeFeet.h"

namespace PaintPerAreaCalculatorClass
{
	class  PaintPerAreaCalculatorTest : public ::testing::Test {
	protected:
		void SetUp() override
		{
			paint1_.setAreaInFeet(360.0);
		}

		PaintPerAreaCalculator paint1_;
		PaintPerAreaCalculator paint2_;
	};

	TEST_F(PaintPerAreaCalculatorTest, ExpectErrorWithNoArea)
	{
		EXPECT_ANY_THROW(paint2_.calculateGallons());
	}
	TEST_F(PaintPerAreaCalculatorTest, Expect2Gallons)
	{
		paint1_.calculateGallons();
		EXPECT_EQ(paint1_.getGallonsNeeded(), 2);
	}
}

namespace RectangleObject
{
	TEST(RectangleObject, CalculateAreaMethod)
	{
		Rectangle testRectangle;

		float testLength = 23.0;
		float testWidth = 12.0;

		testRectangle.setLength(testLength);
		testRectangle.setWidth(testWidth);

		EXPECT_EQ(testRectangle.calculateArea(), 276);
	}
};

namespace ValidateFloatClass
{
	ValidateWholeFeet validateTest;
	const std::string testString = "foo";
	TEST(ValidateFloatClass, DoesNotThrowException)
	{
		std::string wholeNumber = "1";
		EXPECT_NO_THROW(validateTest.ValidateInput(wholeNumber));
	}
	TEST(ValidateFloatClass, DoesThrowException)
	{
		EXPECT_ANY_THROW(validateTest.ValidateInput(testString));
	}
	TEST(ValidateFloatClass, ThrowsInvalidWholeFeet)
	{
		try
		{
			validateTest.ValidateInput(testString);
		}
		catch (std::runtime_error& err)
		{
			std::string expectedString = "Invalid please enter number: ";
			EXPECT_EQ(expectedString, err.what());
		}
	}
}

namespace GetUserIntput
{
	std::string prompt = "What is foo?\n";
	ValidateWholeFeet validateWholeFeet;
	const float testFloat = 1.1;
	TEST(GetUserInput, ReturnsInvalidforString)
	{
		std::stringstream fakeInput;
		std::stringstream output;
		const std::string testString = "Foo";

		UserInput<int> testUserInput(fakeInput, output, validateWholeFeet);

		fakeInput << testString << std::endl << 1;

		testUserInput.promptUser("");

		EXPECT_EQ("Invalid please enter number: ", output.str());
	}
	TEST(GetUserInput, ReturnsInvalidForWholeNum)
	{
		std::stringstream fakeInput;
		std::stringstream output;

		UserInput<int> testUserInput(fakeInput, output, validateWholeFeet);

		fakeInput << testFloat << std::endl << 1;

		testUserInput.promptUser("");

		EXPECT_EQ("Invalid please enter a whole foot: ", output.str());
	}
	TEST(GetUserInput, ExpectAPromtForUser)
	{
		std::stringstream fakeInput;
		std::stringstream output;

		UserInput<std::string> testUserInput(fakeInput, output, validateWholeFeet);

		fakeInput << "1";

		testUserInput.promptUser(prompt);

		EXPECT_EQ(prompt, output.str());
	}

	TEST(GetUserInput, ReturnsInputString)
	{
		std::stringstream fakeInput;
		std::stringstream output;

		UserInput<std::string> testUserInput(fakeInput, output, validateWholeFeet);

		fakeInput << "1";

		std::string returnedString = testUserInput.promptUser(prompt);
		std::string returnedWholeNumberAsString = "1";

		EXPECT_EQ(returnedString, returnedWholeNumberAsString);
	}
}