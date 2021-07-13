#include "Item.h"

void Item::calculateTotal(int quantity) {
	this->quantity = quantity;
	total = price.twoSignificantDigits * quantity;
}