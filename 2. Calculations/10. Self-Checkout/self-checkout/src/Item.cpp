#include "Item.h"

void Item::calculateTotal(int quantity) {
	this->quantity = quantity;
	totalPrice = price.twoSignificantDigits * quantity;
}