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

	TEST(GetUserInput, ReturnsCorrectValue)
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
		fakeInput << testString << std::endl << testString << std::endl << testString << std::endl << testString;

		userPrompt(words, fakeInput, output);

		for (auto& i : words)
		{
			EXPECT_EQ(i[1], "Foo");
		}
	}
}
namespace ConstructOutput
{
	TEST(ConstructOutput, ReturnsConstructedString)
	{
		std::stringstream output;
		std::string mockStory = "Do you * your * * *? That's hailarious!";
		std::string expectedOutput = "Do you Foo your Foo Foo Foo? That's hailarious!";

		std::string words[4][2] = {
			{"noun","Foo"},
			{"verb","Foo"},
			{"Abjective","Foo"},
			{"Adverb","Foo"}
		};

		constructStoryOutput(mockStory, words, output);

		std::string outputString = output.str();

		EXPECT_EQ(expectedOutput, outputString);
	}
}