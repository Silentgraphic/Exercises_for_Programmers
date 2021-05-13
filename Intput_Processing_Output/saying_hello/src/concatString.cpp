#include "saying_hello_header.h"

std::string concatString(std::string fullString, std::string subString)
{
	std::string marker = "*";
	return fullString.replace(fullString.find(marker), fullString.find(marker), subString);
}