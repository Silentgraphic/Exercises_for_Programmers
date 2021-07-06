#include "pch.h"

#include <string>

#include"PaintPerAreaCalculator.h"

namespace PaintPerAreaCalculatorClass
{
	class  PaintPerAreaCalculatorTest : public ::testing::Test {
	protected:
		void SetUp() override
		{
			paint1_.setAreaInFeet(350.0);
		}

		PaintPerAreaCalculator paint1_;
	};
	TEST_F(PaintPerAreaCalculatorTest, Expect2Gallons)
	{
		paint1_.calculateGallons();
		EXPECT_EQ(paint1_.getGallonsNeeded(), 2);
	}
}