#include "printing_quotes.h"

void setEscapedOutput(std::string& name, std::string& quote, std::ostream& output)
{
	output << name + " says " + char(34) + quote + char(34);
}