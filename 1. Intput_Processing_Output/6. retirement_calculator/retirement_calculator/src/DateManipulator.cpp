#include "DateManipulator.h"
#include <stdexcept>

void DateManipulator::subRetirement()
{
	years.push_back(retirementAge - userAge);
}

void DateManipulator::findRetirementYear()
{
	if (years[1] == NULL)
	{
		throw std::invalid_argument("set retirment first");
	}
	else
	{
		years.push_back(years[0] + years[1]);
	}
}
void DateManipulator::setYear(int currentYear)
{
	years.push_back(currentYear);
}
std::vector<int> DateManipulator::getYearVector()
{
	return years;
}