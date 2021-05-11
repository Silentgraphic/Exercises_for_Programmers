#include<string>

#include "pch.h"
#include "saying_hello_header.h"
TEST(StringConcat, ConcatTwoStrings)
{
	ConcatString concatString;
	std::string string1 = "Hello ";
	std::string string2 = "World";
	EXPECT_EQ(concatString.(string1, string2), "Hello World");
}