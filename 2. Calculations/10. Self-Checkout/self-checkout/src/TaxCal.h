#pragma once
#include <vector>
#include "IItem.h"
#include "IDataManager.h"

class TaxCal {
public:
	TaxCal(IDataManager& dataManager);
	unsigned long int calculateTotalExTax();
	unsigned long int calculateTotalIncTax();
private:
	IDataManager& dataManager;
	std::vector<std::unique_ptr<IItem>> itemList;
	const float taxPercent = 5.5;
	unsigned long int calculateTax(unsigned long int total);
};
