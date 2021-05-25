#include "pch.h"
#include "printing_quotes.h"

#include <string>
#include <sstream>

namespace CharacterEscapeOutput
{
	TEST(characterEscapeOutput, returnCorrectOutput)
	{
		std::string name = "Foo";
		std::string quote = "Hello world";
		std::stringstream output;
		std::string expectedOutput = "Foo says \"Hello world\"";
		std::string actualOutput;

		setEscapedOutput(name, quote, output);

		actualOutput = output.str();

		EXPECT_EQ(expectedOutput, actualOutput);
	}
}

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