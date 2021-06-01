#include <string>

#include "pch.h"
#include "simple_math.h"
#include "simple_math_class.h"

namespace SimpleMathClass
{
	int numberone = 2;
	int numbertwo = 2;
	SimpleMath simpleMathTestClass(numberone, numbertwo);

	TEST(SimpleMathClass, Addition)
	{
		int returnedInt = simpleMathTestClass.addition();
		EXPECT_EQ(returnedInt, 4);
	}
	TEST(SimpleMathClass, Subtraction)
	{
		int returnedInt = simpleMathTestClass.subtraction();
		EXPECT_EQ(returnedInt, 0);
	}
	TEST(SimpleMathClass, Mutiply)
	{
		int returnedInt = simpleMathTestClass.mutiply();
		EXPECT_EQ(returnedInt, 4);
	}
	TEST(SimpleMathClass, Division)
	{
		int returnedInt = simpleMathTestClass.division();
		EXPECT_EQ(returnedInt, 1);
	}
}

namespace ConverterFunction
{
	std::string intAsString = "1";

	TEST(ConverterFunction)
	{
		EXPECT_EQ(convertStringToInt(intAsString), 1);
	}
}