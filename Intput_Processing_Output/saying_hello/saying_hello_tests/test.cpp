#include<string>
#include<stdexcept>
#include<sstream>

#include "pch.h"
#include "saying_hello_header.h"

namespace conCatString
{
	std::string subString = "World";
	TEST(StringConcat, ConcatStrings)
	{
		std::string fullString = "Hello *";
		EXPECT_EQ(concatString(fullString, subString), "Hello World");
	}

	TEST(StringConcat, MultipleMarkers)
	{
		std::string fullString = "Hello * *";
		EXPECT_EQ(concatString(fullString, subString), "Hello World World");
	}
	TEST(StringConcat, NoMarkerInFullString)
	{
		std::string fullString = "Hello ";
		EXPECT_THROW(concatString(fullString, subString), std::invalid_argument);
	}
}

namespace consoleInput
{
	TEST(ConsoleInput, ReturnInput)
	{
		std::string testString = "Hello World";
		std::stringstream fakeInput;

		fakeInput << "Hello World";

		std::string returnedString = getConsoleInput(fakeInput, "Enter name:");
		EXPECT_EQ(testString, returnedString);
	}
}

namespace cosnoleOutput
{
}