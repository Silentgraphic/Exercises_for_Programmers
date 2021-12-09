#include "CurrencyConverterAdapter.h"

void CurrencyConverterAdapter::setValues(std::shared_ptr<ICurrency> currency)
{
	//This is a bit messy and needs to be slipt up
	input << userInput.promptUser("How many Euros?").rdbuf();
	while (input >> euros || !input.eof()) {
		if (input.fail()) {
			throw std::invalid_argument("Invalid argument");
		}
	}
	currency->twoSignificantDigits = euros * 1000;

	input << userInput.promptUser("At what percent?").rdbuf();
	while (input >> percentage || !input.eof()) {
		if (input.fail()) {
			throw std::invalid_argument("Invalid argument");
		}
	}
	currency->toDollarsAsPercentage = percentage;
}
