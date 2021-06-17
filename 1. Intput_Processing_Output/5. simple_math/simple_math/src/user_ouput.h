#pragma once
#include <ostream>
#include "simple_math_classes_interface.h"
class UserOuput
{
public:
	UserOuput(ISimpleMath& d) :
		simpleMathObject(d)
	{
	}

	void printUserOutput(std::ostream& output);
private:
	ISimpleMath& simpleMathObject;
};