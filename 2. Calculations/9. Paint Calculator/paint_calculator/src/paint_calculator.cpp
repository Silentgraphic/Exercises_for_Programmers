#include <iostream>
#include <cmath>
#include <map>

#include "ValidateWholeFeet.h"
#include "User_prompt.h"
#include "Rectangle.h"
#include "PaintPerAreaCalculator.h"
#include "String_interpolation.h"

int main() {
	ValidateWholeFeet validateWholeFeet;
	UserInput<float> userInput(std::cin, std::cout, validateWholeFeet);
	Rectangle retangle;
	PaintPerAreaCalculator paintCal;

	float width = userInput.promptUser("Please enter width of ceiling:");
	float length = userInput.promptUser("Please enter length of ceiling:");

	retangle.setWidth(width);
	retangle.setLength(length);

	float area = std::ceil(retangle.calculateArea());

	paintCal.setAreaInFeet(area);
	paintCal.calculateGallons();

	std::map<std::string, float> subStrings = {
		{"gallons" , paintCal.getGallonsNeeded()},
		{"area", area}
	};

	std::cout << StringInter::interpolateString<float>("You will need {gallons} gallons \nTo cover {area} feet sq", subStrings) << std::endl;
}