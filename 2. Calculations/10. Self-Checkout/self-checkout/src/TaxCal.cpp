#include <cmath>

#include "TaxCal.h"

TaxCal::TaxCal(std::vector<IItem*> itemList) :
	itemList(itemList) {
	calculateTax();
}

unsigned long int TaxCal::calculateTotalExTax() {
	unsigned long int total = 0;
	for (auto& i : itemList) {
		total += i->totalPrice;
	}
	return total;
}

unsigned long int  TaxCal::calculateTotalIncTax() {
	return tax + calculateTotalExTax();
}

void TaxCal::calculateTax() {
	tax = std::round((calculateTotalExTax() * taxPercent) / 1000) * 10;
}