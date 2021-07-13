#pragma once

#include"ICurrency.h"

class Item {
public:
	Item(ICurrency& price) :
		price(price) {
	};
	float total;
	void calculateTotal(int quantity);
private:
	ICurrency& price;
	int quantity;
};
