#include "pch.h"
#include "mad_lib.h"
#include <sstream>

namespace GetUserInput
{
	const std::string testString = "Foo";
	TEST(GetUserInput, PromptUser)
	{
		GetWords s;
		std::stringstream fakeInput;
		std::stringstream output;

		std::string expectedString = "Enter a noun: Foo \n Enter a verb: Foo \n Enter a abjective: Foo\n Enter a abverb: Foo\n";

		fakeInput << testString;

		s.userPrompt(fakeInput, output);

		EXPECT_EQ(expectedString, output.str());
	}
}