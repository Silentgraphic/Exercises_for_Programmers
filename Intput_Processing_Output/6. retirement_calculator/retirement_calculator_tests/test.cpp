#include "pch.h"
#include "DateManipulator.h"
#include "getDate.h"
#include "convertStringToInt.h"
#include "userPrompt.h"

#include <string>
#include <sstream>

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