#include "saying_hello_header.h"
#include<stdexcept>

std::string concatString(std::string fullString, std::string subString)
{
	std::string marker = "*";
	rsize_t pos = fullString.find(marker);
	if (pos == std::string::npos)
	{
		throw std::invalid_argument("No string marker found");
	}
	else
	{
		return fullString.replace(pos, fullString.find(marker), subString);
	}
}