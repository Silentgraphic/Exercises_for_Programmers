#pragma once
class ISimpleMath
{
public:
	virtual int addition() = 0;
	virtual int subtraction() = 0;
	virtual int multiply() = 0;
	virtual int division() = 0;
	virtual int getFirstNumber() = 0;
	virtual int getSecondNumber() = 0;
};