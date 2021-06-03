#pragma once
#include "pch.h"
#include "simple_math_classes_interface.h"

class MockSimpleMath :public ISimpleMath {
public:
	MOCK_METHOD(int, getFirstNumber, (), (override));
	MOCK_METHOD(int, getSecondNumber, (), (override));
	MOCK_METHOD(int, addition, (), (override));
	MOCK_METHOD(int, subtraction, (), (override));
	MOCK_METHOD(int, multiply, (), (override));
	MOCK_METHOD(int, division, (), (override));
};