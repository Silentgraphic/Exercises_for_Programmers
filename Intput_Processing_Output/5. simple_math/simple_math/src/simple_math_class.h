#pragma once
class SimpleMath
{
private:
	int firstNumber;
	int secondNumber;
public:
	SimpleMath(int i, int x) :
		firstNumber(i),
		secondNumber(x)
	{
	};

	int addition();
	int subtraction();
	int mutiply();
	int division();
};