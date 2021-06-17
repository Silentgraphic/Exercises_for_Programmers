#pragma once

#include <string>
#include <sstream>

void setEscapedOutput(std::string& name, std::string& quote, std::ostream& output);

std::string getUserString(std::string& prompt, std::istream& input, std::ostream& output);