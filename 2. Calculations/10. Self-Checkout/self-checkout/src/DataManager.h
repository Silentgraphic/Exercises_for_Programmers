#pragma once
#include <vector>
#include <utility>
#include <memory>

#include "ICurrency.h"
#include "IItem.h"
#include "IDataManager.h"
#include "IUserInput.h"

#include "Item.h"
#include "USD.h"

class DataManager : public IDataManager {
public:
	//Need to a way to choose validator without creating new class
	DataManager(IUserInput& userInputPrice, IUserInput& userInputQuantity) :
		userInputPrice(userInputPrice),
		userInputQuantity(userInputQuantity) {
	};
	std::unique_ptr<IItem> getItems();
private:
	IUserInput& userInputPrice;
	IUserInput& userInputQuantity;
	std::unique_ptr<ICurrency> getUserIntput();
};
