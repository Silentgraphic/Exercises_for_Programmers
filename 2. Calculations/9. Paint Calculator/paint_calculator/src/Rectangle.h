#pragma once
class Rectangle {
public:
	Rectangle();
	void setLength(float height);
	void setWidth(float width);
	float calculateArea();
private:
	float height;
	float width;
};
