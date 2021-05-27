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

		userPrompt(words, fakeInput, output);

		EXPECT_EQ(expectedString, output.str());
	}

	TEST(GetUserInput, AcceptsStringInput)
	{
		std::stringstream fakeInput;
		std::stringstream output;

		std::string words[4][2] = {
		{"noun"},
		{"verb"},
		{"Abjective"},
		{"Adverb"}
		};

		//God this is a bad way to do this but it's the only way I can think of
		fakeInput << "Foo" << std::endl << "Foo" << std::endl << "Foo" << std::endl << "Foo";

		userPrompt(words, fakeInput, output);

		for (auto& i : words)
		{
			EXPECT_EQ(i[1], "Foo");
		}
	}
}