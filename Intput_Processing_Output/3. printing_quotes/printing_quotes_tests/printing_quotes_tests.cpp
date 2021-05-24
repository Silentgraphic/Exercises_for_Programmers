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
		std::string expectedOutput = "Foo says \" Hello World \"";
		std::string actualOutput;

		setEscapedOutput(name, quote, output);

		actualOutput = output.str();

		EXPECT_EQ(expectedOutput, actualOutput);
	}
}