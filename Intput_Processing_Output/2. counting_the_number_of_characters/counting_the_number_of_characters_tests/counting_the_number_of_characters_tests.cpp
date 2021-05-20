#include <sstream>

#include "pch.h"
#include "counting_the_number_of_characters.h"

namespace consoleInput
{
	TEST(ConsoleInput, ReturnInput)
	{
		std::string testString = "Hello World";
		std::stringstream fakeInput;

		fakeInput << "Hello World";

		std::string returnedString = getConsoleInput(fakeInput);
		EXPECT_EQ(testString, returnedString);
	}
}