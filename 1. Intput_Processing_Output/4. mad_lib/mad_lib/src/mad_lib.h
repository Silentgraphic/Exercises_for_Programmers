#pragma once
#include <sstream>
#include <vector>

void userPrompt(std::string(&words)[4][2], std::istream& input, std::ostream& output);

void constructStoryOutput(std::string& story, std::string(&words)[4][2], std::ostream& output);