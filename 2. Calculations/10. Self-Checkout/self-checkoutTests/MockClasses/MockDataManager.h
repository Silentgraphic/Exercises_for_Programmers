#pragma once

#include <memory>

#include "IItem.h"
#include "IDataManager.h"

class MockDataManager : public IDataManager {
public:
	MOCK_METHOD(std::unique_ptr<IItem>, getItems, ());
private:
};
