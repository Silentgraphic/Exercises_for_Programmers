#pragma once
#include "pch.h"
#include "simple_math_classes_interface.h"

class MockSimpleMath :public ISimpleMath {
public:
	MOCK_METHOD(int, addition, ());
	MOCK_METHOD(int, subtraction, ());
	MOCK_METHOD(int, mutiply, ());
	MOCK_METHOD(int, division, ());
};