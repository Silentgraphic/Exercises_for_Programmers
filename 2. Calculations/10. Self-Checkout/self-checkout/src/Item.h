#pragma once

#include"ICurrency.h"

#include "IItem.h"

class Item : public IItem {
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
