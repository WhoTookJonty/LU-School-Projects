//Circle.h
#pragma once

class Circle {
public:
	Circle();
	void calcCircumference();
	void calcArea();
	void setRadius(float newRadius);
	float getRadius() const;
	void showData();

private:
	float radius;
};