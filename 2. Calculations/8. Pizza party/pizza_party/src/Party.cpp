#include "Party.h"

void Party::setAmountOfPizza(int amountOfPizza)
{
	this->amountOfPizza = amountOfPizza;
}

void Party::setAmountOfPeople(int amountOfPeople)
{
	this->amountOfPeople = amountOfPeople;
}

int* Party::dividePizza()
{
	int pizzaSlices[2];
	float slicesPerPerson;
	float amountOfSlices;

	amountOfSlices = amountOfPizza * slicesPerPizza;

	slicesPerPerson = amountOfSlices / amountOfPeople;

	pizzaSlices[0] = slicesPerPerson;
	pizzaSlices[1] = (int)amountOfSlices % amountOfPeople;
	return pizzaSlices;
}