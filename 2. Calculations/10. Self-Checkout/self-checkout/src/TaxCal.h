#pragma once
#include <vector>
#include "IItem.h"
#include "ITaxCal.h"

class TaxCal : public ITaxCal {
public:
	TaxCal(std::vector<IItem*> itemList);
	unsigned long int calculateTotalExTax();
	unsigned long int calculateTotalIncTax();
	unsigned long int tax;
private:
	std::vector<IItem*> itemList;
	const float taxPercent = 5.5;
	void calculateTax();
};
