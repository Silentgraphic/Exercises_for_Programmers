#pragma once

class DateManipulator
{
public:
	DateManipulator(int currentYear, int userAge, int retirementAge) :
		currentYear(currentYear),
		userAge(userAge),
		retirementAge(retirementAge)
	{
	};

	int subRetirement();
private:
	int currentYear;
	int userAge;
	int retirementAge;
};