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
		int* pizzaSlicesTest = party_.dividePizza();
		EXPECT_EQ(pizzaSlicesTest[0], 2);
	}

	TEST_F(PartyTest, DivideThePizzaUpExpectNoLeftOvers)
	{
		int* pizzaSlicesTest = party_.dividePizza();
		EXPECT_EQ(pizzaSlicesTest[1], 0);
	}

	TEST_F(PartyTest, DivideThePizzaUpExpecEvenAmount)
	{
		int* pizzaSlicesTest = party_.dividePizza();
		int parity = pizzaSlicesTest[0] % 2;
		EXPECT_EQ(parity, 0);
	}
}