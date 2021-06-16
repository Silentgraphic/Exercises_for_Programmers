#include "DateManipulator.h"

void DateManipulator::subRetirement()
{
	years.push_back(retirementAge - userAge);
}

void DateManipulator::findRetirementYear()
{
	years.push_back(years[0] + retirementAge);
}
void DateManipulator::setYear(int currentYear)
{
	years.push_back(currentYear);
}
std::vector<int> DateManipulator::getYearVector()
{
	return years;
}