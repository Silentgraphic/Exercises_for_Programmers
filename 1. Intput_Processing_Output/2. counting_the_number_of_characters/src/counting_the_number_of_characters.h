#pragma once
#include <string>
#include <sstream>

std::string getUserString(std::istream& input, std::ostream& output);

void charCountOutput(std::string& fullString, int& charCount, std::ostream& output);

int charCount(std::string& userString);