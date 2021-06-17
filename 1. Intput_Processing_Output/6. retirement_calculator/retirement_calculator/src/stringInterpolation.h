#pragma once
#include <string>
#include <vector>
#include <sstream>

template<typename T>
inline std::string stringInter(std::string fullString, const std::vector<T>& subString)
{
	const std::string marker = "*";
	rsize_t pos;
	int i = 0;

	pos = fullString.find(marker);
	if (pos == std::string::npos)
	{
		throw std::invalid_argument("No string markers found");
	}
	else
	{
		while (pos != std::string::npos)
		{
			std::stringstream subStringElement;
			//convert elements to a string
			subStringElement << subString[i];

			//split into the rest of the string
			std::string subStringSplit;
			subStringSplit = fullString.substr(pos + 1, fullString.size());

			//find the marker in the fullstring and replace it
			fullString = fullString.replace(pos, fullString.size(), subStringElement.str());
			fullString += subStringSplit;
			pos = fullString.find(marker);
			i++;
		};
	}
	return fullString;
}