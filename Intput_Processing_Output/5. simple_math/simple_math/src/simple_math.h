#pragma once
#include <string>
#include <sstream>

int convertStringToInt(std::string& valueToConvert);

std::string userPrompt(const std::string& prompt, std::istream& input, std::ostream& output);