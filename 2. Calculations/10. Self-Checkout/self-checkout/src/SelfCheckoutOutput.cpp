#include "SelfCheckoutOutput.h"

#include <exception>

SelfCheckoutOutput::SelfCheckoutOutput(std::ostream& output) : output(output) {
}

void SelfCheckoutOutput::printOutput(std::map<std::string, long double>& subStrings, std::string outputString) {
	convertToReadableFormat(subStrings);
	outputString = StringInter::interpolateString<long double>(outputString, subStrings);
	output << outputString << std::endl;
}

void SelfCheckoutOutput::convertToReadableFormat(std::map<std::string, long double>& subStrings) {
	for (auto price : subStrings) {
		subStrings.insert_or_assign(price.first, price.second / 1000);
	}
}