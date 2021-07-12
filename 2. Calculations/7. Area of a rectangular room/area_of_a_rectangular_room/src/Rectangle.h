#pragma once
class Rectangle
{
public:
	Rectangle();
	void setLength(double height);
	void setWidth(double width);
	double calculateArea();
private:
	double height;
	double width;
};
