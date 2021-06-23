//I am using Gtest as a separate project and linkinging it in the pch.h
//instead of using the build in Gtest adapter in VS as it currently has not been
//updated and as a result does not include Gmock
//To add test framework back in follow this StackOverflow answer
//https://stackoverflow.com/questions/60486110/how-to-use-googlemock-in-visual-studio
#include "pch.h"
#include "Rectangle.h"
#include "convert_to_meters.h"

namespace RectangleObject
{
	TEST(RectangleObject, CalculateAreaMethod)
	{
		Rectangle testRectangle;

		double testHeight = 23.0;
		double testWidth = 12.0;

		testRectangle.setHeight(testHeight);
		testRectangle.setWidth(testWidth);

		EXPECT_EQ(testRectangle.calculateArea(), 276);
	}
};

namespace ConvertToMeters
{
	TEST(ConvertToMeters, CovertsWholeFeet)
	{
		double testLengthInFeet = 12.0;
		double testLengthInMeters = convertToMeters(testLengthInFeet);
		EXPECT_FLOAT_EQ(testLengthInMeters, 3.66);
	}

	TEST(ConvertToMeters, ConversFeetAndInches)
	{
		double testLengthInFeet = 12.5;
		double testLengthInMeters = convertToMeters(testLengthInFeet);
		EXPECT_FLOAT_EQ(testLengthInMeters, 3.81);
	}
}