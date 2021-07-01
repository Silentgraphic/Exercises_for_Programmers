#pragma once
#include <string>
#include <sstream>
#include <map>

class StringInter
{
public:
	template <typename T>
	std::string interpolateString(std::string fullString, const std::map <std::string, T>& subStrings)
	{
		rsize_t counter = 0;
		for (const auto& [marker, replacementWord] : subStrings)
		{
			counter++;
			rsize_t pos;

			pos = fullString.find("{" + marker + "}");
			if (pos == std::string::npos)
			{
				if (counter == subStrings.size())
				{
					throw std::invalid_argument("No string markers found");
				}
				continue;
			}
			else
			{
				//convert elements to a string
				std::stringstream subStringElement{};
				subStringElement << subStrings.at(marker);

				//split into the rest of the string
				std::string subStringSplit;
				subStringSplit = fullString.substr(pos + replacementWord.size() + 2, fullString.size());

				//find the marker in the fullstring and replace it
				fullString = fullString.replace(pos, fullString.size(), subStringElement.str());
				fullString += subStringSplit;

				pos = fullString.find("{" + marker + "}");
			}
		}
		return fullString;
	};

private:
};