#pragma once
#include <string>

class UserInputBase {
public:
	UserInputBase(std::istream& input, std::ostream& output) :
		inputStream(input),
		outputStream(output) {
	};
private:
	std::istream& inputStream;
	std::ostream& outputStream;
};
