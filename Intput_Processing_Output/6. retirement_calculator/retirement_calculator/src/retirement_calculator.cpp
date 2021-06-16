#include "getDate.h"
#include "DateManipulator.h"
#include "convertStringToInt.h"
#include "userPrompt.h"
#include "stringInterpolation.h"
#include "consoleOutput.h"

#include <iostream>
#include <vector>

int main()
{
	std::string currentAgeString = userPrompt((std::string)"What is your current age? ", std::cin, std::cout);
	std::string retireAgeString = userPrompt((std::string)"What age would you like to retire? ", std::cin, std::cout);

	int currentAge = convertStringToInt(currentAgeString);
	int retireAge = convertStringToInt(retireAgeString);

	DateManipulator dateManipulator(currentAge, retireAge);
	dateManipulator.subRetirement();
	dateManipulator.setYear(getDate());
	dateManipulator.findRetirementYear();

	std::string fullString = stringInter<int>((std::string)"You have * years until you can retire\nIt's * you can retire in *", dateManipulator.getYearVector());
	consoleOutput(std::cout, fullString);
}