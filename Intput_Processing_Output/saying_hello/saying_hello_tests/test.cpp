#include<string>
#include<stdexcept>

#include "pch.h"
#include "saying_hello_header.h"
TEST(StringConcat, ConcatStrings)
{
	std::string fullString = "Hello *";
	std::string subString = "World";
	EXPECT_EQ(concatString(fullString, subString), "Hello World");
}

TEST(StringConcat, NoMarkerInFullString)
{
	std::string fullString = "Hello ";
	std::string subString = "World";
	EXPECT_THROW(concatString(fullString, subString), std::invalid_argument);
}