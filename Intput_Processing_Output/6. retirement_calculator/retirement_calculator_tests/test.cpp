#include "pch.h"
#include "DateManipulator.h"

namespace DateManipulatorTests
{
	DateManipulator testDateManipulator(2021, 25, 65);
	TEST(SubRetirement, Expect40Years)
	{
		int returnedYear = testDateManipulator.subRetirement();
		EXPECT_EQ(returnedYear, 40);
	}
}