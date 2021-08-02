#include <cmath>

#include "TaxCal.h"

TaxCal::TaxCal(IDataManager& dataManager) : dataManager(dataManager) {
}

unsigned long int TaxCal::calculateTotalExTax() {
	if (itemList.size() == 0) {
		generateItemList();
	}
	for (auto& i : itemList) {
		total += i->totalPrice;
	}
	return total;
}

unsigned long int  TaxCal::calculateTotalIncTax() {
	return calculateTax() + total;
}

unsigned long int TaxCal::calculateTax() {
	if (total == 0) {
		calculateTotalExTax();
	}
	return std::round((total * taxPercent) / 1000) * 10;
}

void TaxCal::generateItemList() {
	for (size_t i = 0; i < 3; i++) {
		itemList.push_back(std::move(dataManager.getItems()));
	}
}