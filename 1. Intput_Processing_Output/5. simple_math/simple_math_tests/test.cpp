//I am using Gtest as a separate project and linkinging it in the pch.h
//instead of using the build in Gtest adapter in VS as it currently has not been
//updated and as a result does not include Gmock
//To add test framework back in follow this StackOverflow answer
//https://stackoverflow.com/questions/60486110/how-to-use-googlemock-in-visual-studio
#include "pch.h"

#include <string>
#include <sstream>

#include "simple_math.h"
#include "simple_math_class.h"
#include "mock_simple_math.h"
#include "user_ouput.h"

using ::testing::Return;

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
		int returnedInt = simpleMathTestClass.multiply();
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

namespace UserOutput
{
	std::stringstream output;
	MockSimpleMath simpleMathObject;
	UserOuput userPromptObject(simpleMathObject);
	TEST(UserOutput, WillCallAddition)
	{
		EXPECT_CALL(simpleMathObject, addition())
			.Times(1);
	}

	TEST(UserOutput, WillCallSubtraction)
	{
		EXPECT_CALL(simpleMathObject, subtraction())
			.Times(1);
	}

	TEST(UserOutput, WillCallMultiply)
	{
		EXPECT_CALL(simpleMathObject, multiply())
			.Times(1);
	}

	TEST(UserOutput, WillCallDivision)
	{
		EXPECT_CALL(simpleMathObject, division())
			.Times(1);
	}
	TEST(UserOutput, CorrectOutput)
	{
		userPromptObject.printUserOutput(output);
		EXPECT_EQ(output.str(), "0+0=0\n0-0=0\n0*0=0\n0/0=0\n");
	}
}