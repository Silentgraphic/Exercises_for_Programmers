#pragma once
#include "simple_math_classes_interface.h"
class SimpleMath : public ISimpleMath
{
public:
	SimpleMath(int i, int x) :
		firstNumber(i),
		secondNumber(x)
	{
	}

	int addition();
	int subtraction();
	int multiply();
	int division();
private:
	int firstNumber;
	int secondNumber;
};