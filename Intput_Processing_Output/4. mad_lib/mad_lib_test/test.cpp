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
		std::string words[4][2] = {
		{"noun"},
		{"verb"},
		{"Abjective"},
		{"Adverb"}
		};

		std::string expectedString = "Enter a noun:Enter a verb:Enter a Abjective:Enter a Adverb:";

		fakeInput << testString;

		userPrompt(words, fakeInput, output);

		EXPECT_EQ(expectedString, output.str());
	}
}