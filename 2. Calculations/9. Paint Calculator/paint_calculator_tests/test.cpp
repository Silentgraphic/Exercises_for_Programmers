#include "pch.h"

#include <string>

#include"PaintPerAreaCalculator.h"
#include "Rectangle.h"
#include "User_prompt.h"

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

namespace GetUserIntput
{
	const std::string testString = "Foo";
	std::string prompt = "What is foo?\n";

	TEST(GetUserInput, ExpectAPromtForUser)
	{
		std::stringstream fakeInput;
		std::stringstream output;

		UserInput<std::string> testUserInput(fakeInput, output);

		fakeInput << testString;

		testUserInput.promptUser(prompt);

		std::string expectedOutput = "What is foo?\n";

		EXPECT_EQ(expectedOutput, output.str());
	}

	TEST(GetUserInput, ReturnsInputString)
	{
		std::stringstream fakeInput;
		std::stringstream output;

		UserInput<std::string> testUserInput(fakeInput, output);

		fakeInput << testString;

		std::string returnedString = testUserInput.promptUser(prompt);

		EXPECT_EQ(returnedString, testString);
	}
	TEST(GetUserInput, ReturnsInvalid)
	{
		std::stringstream fakeInput;
		std::stringstream output;

		UserInput<int> testUserInput(fakeInput, output);

		float testFloat = 1.1;

		fakeInput << testString << std::endl << 1;

		testUserInput.promptUser("");

		EXPECT_EQ("Invalid please enter a whole foot: ", output.str());
	}
}