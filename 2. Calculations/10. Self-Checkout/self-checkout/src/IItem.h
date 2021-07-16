#pragma once
#include "ICurrency.h"

class IItem {
public:
	virtual void calculateTotal(int quantity) = 0;
	unsigned long int totalPrice;
	virtual void setCurrency(ICurrency& price) = 0;
};
