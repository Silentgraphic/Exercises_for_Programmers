#include "PaintPerAreaCalculator.h"

void PaintPerAreaCalculator::setAreaInFeet(float areaInFeet)
{
	this->areaInFeet = areaInFeet;
}

int PaintPerAreaCalculator::getGallonsNeeded()
{
	return gallonsNeeded;
}

void PaintPerAreaCalculator::calculateGallons()
{
	try
	{
		gallonsNeeded = roundUpToNearestGallon(areaInFeet / conversionRateinFeet);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int PaintPerAreaCalculator::roundUpToNearestGallon(float paint)
{
	if (!paint)
	{
		throw"Set area memeber first";
	}
	else
	{
		return std::ceil(paint);
	}
}