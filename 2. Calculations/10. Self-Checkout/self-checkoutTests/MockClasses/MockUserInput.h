#pragma once

#include "IUserInput.h"

class  MockUserInput : public IUserInput {
public:
	MOCK_METHOD(void, promptUser, (std::string prompt));
};
