#include "pch.h"
#include "mad_lib.h"
#include <sstream>
#include <vector>

namespace GetUserInput
{
	const std::string testString = "Foo";
	TEST(GetUserInput, PromptUser)
	{
		std::stringstream fakeInput;
		std::stringstream output;
		std::vector<std::string> words[4] = {
		{"noun"},
		{"verb"},
		{"Abjective"},
		{"Adverb"}
		};

		std::string expectedString = "Enter a noun: Foo\n Enter a verb: Foo\n Enter a abjective: Foo\n Enter a abverb: Foo\n";

		fakeInput << testString;

		userPrompt(words, fakeInput, output);

		EXPECT_EQ(expectedString, output.str());
	}
}