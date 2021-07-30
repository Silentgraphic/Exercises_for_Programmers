#include "DataManager.h"

std::unique_ptr<IItem> DataManager::getItems() {
	long int amountOfItems = 0;
	userInputQuantity.promptUser("How Many Items ") >> amountOfItems;

	std::unique_ptr<ICurrency> uSD = std::move(getUserIntput());
	auto item = std::move(std::make_unique<Item>(*uSD));
	item->calculateTotal(amountOfItems);
	return std::move(item);
}

std::unique_ptr<ICurrency> DataManager::getUserIntput() {
	long double userValue = 0;
	userInputPrice.promptUser("Price ") >> userValue;
	return std::unique_ptr<ICurrency>(new USD(userValue));
}