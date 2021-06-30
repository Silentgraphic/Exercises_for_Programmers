#pragma once

class Party
{
public:
	void setAmountOfPizza(int amountOfPizza);
	void setAmountOfPeople(int amountOfPeople);
	int* dividePizza();
private:
	int amountOfPizza;
	int amountOfPeople;
	const int slicesPerPizza = 8;
};
