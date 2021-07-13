#pragma once

#include"ICurrency.h"

class Item {
public:
	Item(ICurrency& price) :
		price(price) {
	};
	unsigned long int totalPrice;
	void calculateTotal(int quantity);
private:
	ICurrency& price;
	int quantity;
};
