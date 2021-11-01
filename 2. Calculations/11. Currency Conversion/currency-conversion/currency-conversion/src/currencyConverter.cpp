#include <cmath>

#include "CurrencyConverter.h"
#include "ICurrency.h"


void CurrencyConverter::setCurrency(ICurrency& currencyToConvert)
{
}

long int CurrencyConverter::convertToDollars()
{
	return (currencyToBeConverted.twoSignificantDigits * currencyToBeConverted.toDollarsAsPercentage)/100;
}

long int CurrencyConverter::convertToEuros()
{
	return (currencyToBeConverted.twoSignificantDigits * currencyToBeConverted.toEurosAsPercentage)/100;
}
