#pragma once
#include<vector>

class DateManipulator
{
public:
	DateManipulator(int userAge, int retirementAge) :
		userAge(userAge),
		retirementAge(retirementAge)
	{
	};

	void subRetirement();
	void findRetirementYear();
	void setYear(int year);
	std::vector<int> getYearVector();
private:
	int userAge;
	int retirementAge;
	std::vector<int> years;
};