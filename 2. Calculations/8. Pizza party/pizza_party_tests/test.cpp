#include <string>

#include "pch.h"
#include "Party.h"
#include "User_prompt.h"

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