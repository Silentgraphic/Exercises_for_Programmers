#include "Item.h"

void Item::calculateTotal(ICurrency& price, int quantity) {
	this->priceTwoDecimals = price.twoSignificantDigits;
	this->quantity = quantity;
	total = priceTwoDecimals * quantity;
}