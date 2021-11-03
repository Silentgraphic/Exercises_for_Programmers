#pragma once

#include "IUserInput.h"
#include <string>

class  MockUserInput : public IUserInput {
public:
	MOCK_METHOD(std::stringstream&, promptUser, (std::string prompt));
};
