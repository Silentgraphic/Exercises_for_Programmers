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
	DataManager(IUserInput& userInput) :
		userInput(userInput) {
	};
	std::unique_ptr<IItem> getItems();
private:
	IUserInput& userInput;
	std::unique_ptr<ICurrency> getUserIntput();
};
