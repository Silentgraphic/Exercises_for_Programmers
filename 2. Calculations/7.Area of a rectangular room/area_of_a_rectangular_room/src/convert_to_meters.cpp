#include "convert_to_meters.h"
#include <cmath>

double convertToMeters(double lengthInFeetAndInches)
{
	const double conversionFactor = 0.3048;
	double feet;
	double inches = std::modf(lengthInFeetAndInches, &feet);
	int lengthInMeters = (int)(((inches + (int)lengthInFeetAndInches) * conversionFactor) * 100 + .5);
	return 	(float)lengthInMeters / 100;
}