#include <iostream>
#include <map>

#include "DataManager.h"
#include "User_prompt.h"
#include "TaxCal.h"
#include "ValidateWholeNumber.h"
#include "ValidatePrice.h"
#include "SelfCheckoutOutput.h"

int main() {
	ValidateWholeNumber wholeNumberValidator;
	ValidatePrice priceValidator;
	UserInput userInput1(std::cin, std::cout, priceValidator);
	UserInput userInput2(std::cin, std::cout, wholeNumberValidator);
	DataManager datManager(userInput1, userInput2);
	TaxCal taxCal(datManager);
	std::map<std::string, long double> substrings = { {"subTotal",taxCal.calculateTotalExTax()}, {"tax",taxCal.calculateTax()}, {"total",taxCal.calculateTotalIncTax()} };
	SelfCheckoutOutput checkout(std::cout);
	checkout.printOutput(substrings, "SubTotal:${subTotal} \nTax:${tax} \nTotal:${total}");
}