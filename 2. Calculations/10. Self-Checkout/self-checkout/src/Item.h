#pragma once

#include"ICurrency.h"

#include "IItem.h"

class Item : public IItem {
public:
	Item(ICurrency& price) :
		price(price) {
	};
	void calculateTotal(int quantity);
	void setCurrency(ICurrency& price);
private:
	ICurrency& price;
	int quantity;
};
