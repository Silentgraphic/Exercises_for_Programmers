#include "Rectangle.h"

Rectangle::Rectangle() {}
void Rectangle::setLength(float rectangleHeight)
{
	height = rectangleHeight;
}
void Rectangle::setWidth(float rectangleWidth)
{
	width = rectangleWidth;
}
float Rectangle::calculateArea()
{
	return width * height;
}
;