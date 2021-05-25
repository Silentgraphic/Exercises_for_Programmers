#include <iostream>
#include "printing_quotes.h"

int main()
{
	std::string quotePrompt = "What is the quote: ";
	std::string namePrompt = "Who said it: ";

	std::string quote = getUserString(quotePrompt, std::cin, std::cout);
	std::string name = getUserString(namePrompt, std::cin, std::cout);
	setEscapedOutput(name, quote, std::cout);
	std::cin;
}