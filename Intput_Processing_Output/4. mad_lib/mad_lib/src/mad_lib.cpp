#include <iostream>
#include <string>
#include <vector>
#include "mad_lib.h"

int main()
{
	std::string story = "Do you Verb your Abjective Noun Adverb? That's hailarious!";
	std::string words[4][2] = {
		{"Noun"},
		{"Verb"},
		{"Abjective"},
		{"Adverb"}
	};

	userPrompt(words, std::cin, std::cout);

	constructStoryOutput(story, words, std::cout);
}