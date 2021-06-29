#include "pch.h"
#include "Party.h"

namespace PartyClass
{
	class PartyTest : public ::testing::Test {
	protected:
		void SetUp() override
		{
			party_.setAmountOfPizza(2);
			party_.setAmountOfPeople(8);
		}

		Party party_;
	};
	TEST_F(PartyTest, DivideThePizzaUpExpectCorrectAmount)
	{
		int* pizzaSlices = party_.dividePizza();
		int amountOfPizzaSlices = pizzaSlices[0];
		EXPECT_EQ(amountOfPizzaSlices, 2);
	}

	TEST_F(PartyTest, DivideThePizzaUpExpectNoLeftOvers)
	{
		int* pizzaSlices = party_.dividePizza();
		EXPECT_EQ(pizzaSlices[1], 0);
	}

	TEST_F(PartyTest, DivideThePizzaUpExpecEvenAmount)
	{
		int* pizzaSlices = party_.dividePizza();
		int parity = pizzaSlices[0] % 2;
		EXPECT_EQ(parity, 0);
	}
}