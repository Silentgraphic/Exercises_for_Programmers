#pragma once

#include"ICurrency.h"

class Item {
public:
	float total;
	void calculateTotal(ICurrency& price, int quantity);
private:
	long int priceTwoDecimals;
	int quantity;
};
