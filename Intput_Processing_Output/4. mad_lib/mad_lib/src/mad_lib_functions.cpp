#include "mad_lib.h"

void userPrompt(std::string(&words)[4][2], std::istream& input, std::ostream& output)
{
	for (auto& i : words)
	{
		std::string userInput;
		output << "Enter a " << i[0] << ":";
		input >> userInput;
		i[1] = userInput;
	}
}

void constructStoryOutput(std::string& story, std::string(&words)[4][2], std::ostream& output)
{
	const std::string marker = "*";
	rsize_t pos = story.find(marker);

	while (pos != std::string::npos)
	{
		int counter = 1;
		story = story.replace(pos, 1, words[counter][1]);
		pos = story.find(marker);
	};

	output << story;
}