#pragma once
#include <memory>

class IDataManager {
public:
	virtual std::unique_ptr<IItem> getItems() = 0;
};