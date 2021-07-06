#pragma once
class PaintPerAreaCalculator
{
public:
	void setAreaInFeet(float areaInFeet);
	int getGallonsNeeded();
	void calculateGallons();
private:
	int gallonsNeeded;
	int areaInFeet;
	const int conversionRateinFeet = 350;
};
