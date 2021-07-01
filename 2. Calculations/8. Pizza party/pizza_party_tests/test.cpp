#include <string>
#include <map>

#include "pch.h"
#include "Party.h"
#include "User_prompt.h"
#include "String_interpolation.h"

namespace PartyClass
{
	class PartyTest : public ::testing::Test {
	protected:
		void SetUp() override
		{
			party1_.setAmountOfPizza(2);
			party1_.setAmountOfPeople(8);
			party2_.setAmountOfPizza(2);
			party2_.setAmountOfPeople(9);
		}

		Party party1_;
		Party party2_;
	};
	TEST_F(PartyTest, DivideThePizzaUpExpect2)
	{
		int* pizzaSlices = party1_.dividePizza();
		int amountOfPizzaSlices = pizzaSlices[0];
		EXPECT_EQ(amountOfPizzaSlices, 2);
	}

	TEST_F(PartyTest, DivideThePizzaUpExpectNoLeftOvers)
	{
		int* pizzaSlices = party1_.dividePizza();
		int leftoverPizzaSlices = pizzaSlices[1];
		EXPECT_EQ(leftoverPizzaSlices, 0);
	}

	TEST_F(PartyTest, DivideThePizzaUpExpecEvenAmount)
	{
		int* pizzaSlices = party1_.dividePizza();
		int parity = pizzaSlices[0] % 2;
		EXPECT_EQ(parity, 0);
	}

	TEST_F(PartyTest, DivideThePizzaUpExpect1)
	{
		int* pizzaSlices = party2_.dividePizza();
		int amountOfPizzaSlices = pizzaSlices[0];
		EXPECT_EQ(amountOfPizzaSlices, 1);
	}

	TEST_F(PartyTest, DivideThePizzaUpExpect7LeftOvers)
	{
		int* pizzaSlices = party2_.dividePizza();
		int leftoverPizzaSlices = pizzaSlices[1];
		EXPECT_EQ(leftoverPizzaSlices, 7);
	}
}

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
}

namespace StringInterpolation
{
	const std::map<std::string, std::string> testSubStrings = { {"foo" , "Foo"},{"bar", "Bar"} };
	std::string testSingleMarkerString = "What is foo?";
	std::string testDoubleMarkerString = "What is foo bar?";
	StringInter testStringInterpolation;

	TEST(StringInterpolation, NoMarkerInFullString)
	{
		std::string testStringNoMarker = "What is ?";

		EXPECT_THROW(testStringInterpolation.interpolateString<std::string>(testStringNoMarker, testSubStrings), std::invalid_argument);
	}

	TEST(StringInterpolation, ReturnsStringWithSingleStringInput)
	{
		const std::string expectedString = "What is Foo?";

		std::string returnedString = testStringInterpolation.interpolateString<std::string>(testSingleMarkerString, testSubStrings);

		EXPECT_EQ(expectedString, returnedString);
	}

	TEST(StringInterpolation, ReturnsStringWithMultipleStringInput)
	{
		const std::string expectedString = "What is Foo Bar?";

		std::string returnedString = testStringInterpolation.interpolateString<std::string>(testDoubleMarkerString, testSubStrings);

		EXPECT_EQ(expectedString, returnedString);
	}
}