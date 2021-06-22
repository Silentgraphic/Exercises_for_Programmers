#pragma once
class Rectangle
{
public:
	Rectangle();
	void setHeight(double height);
	void setWidth(double width);
	double calculateArea();
private:
	double height;
	double width;
};
