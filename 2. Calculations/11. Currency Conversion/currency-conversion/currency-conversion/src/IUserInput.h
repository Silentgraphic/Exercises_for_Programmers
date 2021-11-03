#pragma once

#include <string>
#include <sstream>
#include <iostream>

class IUserInput {
public:
	virtual std::stringstream& promptUser(std::string prompt) = 0;
};