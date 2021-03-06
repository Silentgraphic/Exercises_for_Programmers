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

namespace Output
{
	TEST(Output, SetOutput)
	{
		std::string testString = "Hello World";
		int fakeCharCount = 11;
		std::stringstream output;

		std::string expectedOutput = "Hello World has 11 characters";
		std::string actualOutput;

		charCountOutput(testString, fakeCharCount, output);

		actualOutput = output.str();
		EXPECT_EQ(actualOutput, expectedOutput);
	}
}

namespace CharCount
{
	TEST(CharCount, ReturnCorrectCount)
	{
		std::string testString = "Hello World";
		int fakeCharCount = 11;

		int actualCharCount = charCount(testString);

		EXPECT_EQ(actualCharCount, fakeCharCount);
	}
}