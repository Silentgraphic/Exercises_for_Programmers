#include "DataManager.h"

std::unique_ptr<IItem> DataManager::getItems() {
	long int amountOfItems = 0;
	std::stringstream& userString = userInput.promptUser("How Many Items");
	userString >> amountOfItems;

	std::unique_ptr<ICurrency> uSD = std::move(getUserIntput());
	auto item = std::move(std::make_unique<Item>(*uSD));
	item->calculateTotal(amountOfItems);
	return std::move(item);
}

std::unique_ptr<ICurrency> DataManager::getUserIntput() {
	long int userValue = 0;
	std::stringstream& userString = userInput.promptUser("How Many Items");
	userString >> userValue;
	return std::unique_ptr<ICurrency>(new USD(userValue));
}