#include "DateManipulator.h"

int DateManipulator::subRetirement()
{
	return retirementAge - userAge;
}

int DateManipulator::findRetirementYear()
{
	return currentYear + retirementAge;
}