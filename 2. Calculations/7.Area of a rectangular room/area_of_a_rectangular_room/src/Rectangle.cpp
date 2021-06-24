#include "Rectangle.h"

Rectangle::Rectangle() {}
void Rectangle::setLength(double rectangleHeight)
{
	height = rectangleHeight;
}
void Rectangle::setWidth(double rectangleWidth)
{
	width = rectangleWidth;
}
double Rectangle::calculateArea()
{
	return width * height;
}
;