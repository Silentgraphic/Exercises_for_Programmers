#include <iostream>
#include <string>
#include <vector>

#include "convert_to_meters.h"
#include "convertStringToDouble.h"
#include "Rectangle.h"
#include "stringInterpolation.h"
#include "userPrompt.h"
#include "consoleOutput.h"

int main()
{
	std::string length = userPrompt((std::string)"What is the length of the room in feet ", std::cin, std::cout);
	std::string width = userPrompt((std::string)"What is the width of the room in feet ", std::cin, std::cout);
	double lengthInFeet = convertStringToDouble(length);
	double widthInFeet = convertStringToDouble(width);
	double lengthInMeters = convertToMeters(lengthInFeet);
	double widthInMeters = convertToMeters(widthInFeet);

	Rectangle rectangleInFeet;
	Rectangle recatngleInMeters;
	std::vector <double>areas;

	rectangleInFeet.setLength(lengthInFeet);
	rectangleInFeet.setWidth(widthInFeet);
	recatngleInMeters.setLength(lengthInMeters);
	recatngleInMeters.setWidth(widthInMeters);

	areas.push_back(rectangleInFeet.calculateArea());
	areas.push_back(recatngleInMeters.calculateArea());

	std::string prompt = "The Area is \n* in square feet \n* in square meters";
	consoleOutput(std::cout, stringInter(prompt, areas));
}