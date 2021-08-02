#pragma once
#include <vector>
#include "IItem.h"
#include "IDataManager.h"

class TaxCal {
public:
	TaxCal(IDataManager& dataManager);
	unsigned long int calculateTotalExTax();
	unsigned long int calculateTotalIncTax();
	unsigned long int calculateTax();
private:
	unsigned long int total = 0;
	IDataManager& dataManager;
	std::vector<std::unique_ptr<IItem>> itemList;
	const float taxPercent = 5.5;
	void generateItemList();
};
