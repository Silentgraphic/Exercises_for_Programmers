#pragma once
#include <map>
#include <string>

#include "String_interpolation.h"

class SelfCheckoutOutput {
public:
	SelfCheckoutOutput(std::ostream& output);
	void printOutput(std::map<std::string, long double>& subStrings, std::string stringToPrint);
private:
	void convertToReadableFormat(std::map<std::string, long double>& subStrings);
	std::ostream& output;
};
