#include <iostream>
#include "counting_the_number_of_characters.h"

int main()
{
	std::string userString = getUserString(std::cin, std::cout);
	int userCharCount = charCount(userString);
	charCountOutput(userString, userCharCount, std::cout);
}