#include <sstream>

#include "pch.h"
#include "counting_the_number_of_characters.h"

namespace Input
{
	TEST(Input, ShowsPrompt)
	{
		std::stringstream fakeInput;
		std::stringstream output;
		std::string returnedString;

		std::string outputString = "What is the input string: ";
		getUserString(fakeInput, output);

		returnedString = output.str();

		EXPECT_EQ(outputString, returnedString);
	}

	TEST(Input, ReturnInput)
	{
		std::string testString = "Hello World";
		std::stringstream fakeInput;
		std::stringstream output;

		fakeInput << "Hello World";

		std::string returnedString = getUserString(fakeInput, output);
		EXPECT_EQ(testString, returnedString);
	}
}