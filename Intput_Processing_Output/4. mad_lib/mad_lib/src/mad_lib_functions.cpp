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
	int counter = 0;
	rsize_t pos = story.find(words[counter][0]);

	while (pos != std::string::npos)
	{
		int stringLength = words[counter][0].length();
		story = story.replace(pos, stringLength, words[counter][1]);
		counter++;
		pos = story.find(words[counter][0]);
	};

	output << story;
}