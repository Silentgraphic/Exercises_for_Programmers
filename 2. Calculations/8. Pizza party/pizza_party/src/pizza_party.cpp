#include <iostream>
#include <string>
#include <map>

#include "Party.h"
#include "String_interpolation.h"
#include "consoleOutput.h"
#include "User_prompt.h"

int main()
{
	UserInput<int> consolePromptUser(std::cin, std::cout);
	Party pizzaParty;
	StringInter stringInter;

	int amountOfPeople = consolePromptUser.promptUser((std::string)"How many people? ");
	int amountOfPizza = consolePromptUser.promptUser((std::string)"How much pizza? ");

	pizzaParty.setAmountOfPeople(amountOfPeople);
	pizzaParty.setAmountOfPizza(amountOfPizza);

	int* slices = pizzaParty.dividePizza();
	int slicesPerPerson = slices[0];
	int leftOvers = slices[1];

	std::string outputMessage = "{people} people with {pizza} pizzas\nEach person gets {slicesPerPerson} pieces of pizzas\nThere are {leftOvers} slices leftover\n";

	const std::map<std::string, int> subStrings{
		{"people", amountOfPeople},
		{"pizza", amountOfPizza},
		{"slicesPerPerson", slicesPerPerson},
		{"leftOvers", leftOvers},
	};

	outputMessage = stringInter.interpolateString<int>(outputMessage, subStrings);

	consoleOutput(std::cout, outputMessage);
	std::cin.get();
}