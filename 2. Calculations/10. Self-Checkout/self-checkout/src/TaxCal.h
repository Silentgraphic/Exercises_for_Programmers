#pragma once
#include <vector>
#include "IItem.h"

class TaxCal {
public:
	TaxCal(std::vector<IItem*> itemList) :
		itemList(itemList) {
	};
	unsigned long int calculateTotalExTax();
	unsigned long int calculateTotalIncTax();
private:
	std::vector<IItem*> itemList;
};
