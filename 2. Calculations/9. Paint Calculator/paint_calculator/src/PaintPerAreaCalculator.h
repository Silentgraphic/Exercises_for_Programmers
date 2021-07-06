#pragma once
#include<cmath>
#include <exception>
#include <iostream>

class PaintPerAreaCalculator
{
public:
	void setAreaInFeet(float areaInFeet);
	int getGallonsNeeded();
	void calculateGallons();
private:
	int gallonsNeeded = NAN;
	int areaInFeet = NAN;
	const float conversionRateinFeet = 350.0;
	int roundUpToNearestGallon(float paint);
};
