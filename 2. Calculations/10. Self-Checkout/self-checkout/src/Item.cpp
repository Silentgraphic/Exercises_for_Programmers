#include "Item.h"

void Item::calculateTotal(int quantity) {
	this->quantity = quantity;
	totalPrice = price.twoSignificantDigits * quantity;
}

void Item::setCurrency(ICurrency& price) {
	this->price = price;
}