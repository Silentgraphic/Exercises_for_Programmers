#include "pch.h"
#include "DateManipulator.h"
#include "getDate.h"
#include "convertStringToInt.h"
#include "userPrompt.h"
#include "stringInterpolation.h"

#include <string>
#include <sstream>
#include <vector>

namespace DateManipulatorTests
{
	DateManipulator testDateManipulator(2021, 25, 65);
	TEST(SubRetirement, Expect40Years)
	{
		int returnedYear = testDateManipulator.subRetirement();
		EXPECT_EQ(returnedYear, 40);
	}

	TEST(FindRetirementYear, Expect2086)
	{
		int returnedYear = testDateManipulator.findRetirementYear();
		EXPECT_EQ(returnedYear, 2086);
	}
}

namespace GetDateTests
{
	TEST(GetDate, ReturnsInt)
	{
		EXPECT_EQ(typeid(int), typeid(getDate()));
	}
}

namespace StringToInt
{
	TEST(StringToInt, ExpectedIntToBeReturned)
	{
		std::string intAsString = "1";
		EXPECT_EQ(convertStringToInt(intAsString), 1);
	}
}

namespace GetUserIntput
{
	const std::string testString = "Foo";
	std::string prompt = "What is foo?\n";
	TEST(GetUserInput, ExpectAPromtForUser)
	{
		std::stringstream fakeInput;
		std::stringstream output;

		userPrompt(prompt, fakeInput, output);

		std::string expectedOutput = "What is foo?\n";

		EXPECT_EQ(expectedOutput, output.str());
	}

	TEST(GetUserInput, ReturnsInputString)
	{
		std::stringstream fakeInput;
		std::stringstream output;

		fakeInput << testString;

		std::string returnedString = userPrompt(prompt, fakeInput, output);

		EXPECT_EQ(returnedString, testString);
	}
}

namespace StringInterpolation
{
	const std::vector<std::string> testSubStrings = { "foo" , "bar" };
	const std::vector<int> testSubInt = { 1,2 };

	TEST(StringInterpolation, NoMarkerInFullString)
	{
		std::string testString = "What is ?";
		EXPECT_THROW(stringInter<std::string>(testString, testSubStrings), std::invalid_argument);
	}
	TEST(StringInterpolation, ReturnsStringWithSingleStringInput)
	{
		std::string testString = "What is *?";
		std::string expectedString = "What is foo?";

		std::string returnedString = stringInter<std::string>(testString, testSubStrings);

		EXPECT_EQ(expectedString, returnedString);
	}

	TEST(StringInterpolation, ReturnsStringWithMultipleStringInput)
	{
		std::string testString = "What is * *?";
		std::string expectedString = "What is foo bar?";

		std::string returnedString = stringInter<std::string>(testString, testSubStrings);

		EXPECT_EQ(expectedString, returnedString);
	}
	TEST(StringInterpolation, ReturnsStringWithSingleIntInput)
	{
		std::string testString = "What is *?";
		std::string expectedString = "What is 1?";
		std::string returnedString = stringInter<int>(testString, testSubInt);

		EXPECT_EQ(expectedString, returnedString);
	}
	TEST(StringInterpolation, ReturnsStringWithMultipleIntInput)
	{
		std::string testString = "What is * *?";
		std::string expectedString = "What is 1 2?";
		std::string returnedString = stringInter<int>(testString, testSubInt);

		EXPECT_EQ(expectedString, returnedString);
	}
}