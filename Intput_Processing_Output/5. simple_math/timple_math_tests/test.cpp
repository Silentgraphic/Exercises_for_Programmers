#include <string>

#include "pch.h"
#include "simple_math.h"
#include "simple_math_class.h"

namespace SimpleMathClass
{
	int numberone = 2;
	int numbertwo = 2;
	SimpleMath simpleMathTestClass(numberone, numbertwo);

	TEST(SimpleMathClass, Addition)
	{
		int returnedInt = simpleMathTestClass.addition();
		EXPECT_EQ(returnedInt, 4);
	}
	TEST(SimpleMathClass, Subtraction)
	{
		int returnedInt = simpleMathTestClass.subtraction();
		EXPECT_EQ(returnedInt, 0);
	}
	TEST(SimpleMathClass, Mutiply)
	{
		int returnedInt = simpleMathTestClass.mutiply();
		EXPECT_EQ(returnedInt, 4);
	}
	TEST(SimpleMathClass, Division)
	{
		int returnedInt = simpleMathTestClass.division();
		EXPECT_EQ(returnedInt, 1);
	}
}

namespace ConverterFunction
{
	std::string intAsString = "1";

	TEST(ConverterFunction, ExpectAIntToBeReturned)
	{
		EXPECT_EQ(convertStringToInt(intAsString), 1);
	}
}

namespace GetUserIntput
{
	const std::string testString = "Foo";
	std::string prompt = "What is foo?";
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