//Circle.cpp
#include "Circle.h"
#include <iostream>
#include <cmath>

//constant globial variable for pi
const float pi = 3.14159265;


Circle::Circle() {
	setRadius(0);
}

//set the value of radius to user's inputted radius
void Circle::setRadius(float newRadius) {
	radius = newRadius;
}


float Circle::getRadius() const {
	return radius;
}

//calculates and prints Area of circle
void Circle::calcArea() {
	std::cout << "Area: " << pi * pow(getRadius(), (float)2) << std::endl;
}

//calculates and prints Circumference of circle
void Circle::calcCircumference() {
	std::cout << "Circumference: " << 2 * pi * getRadius() << std::endl;
}

//prints value of Circumference AND Area of the circle
void Circle::showData() {
	calcArea();
	calcCircumference();

}