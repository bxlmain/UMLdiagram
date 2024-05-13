#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
#include <string>
#include "Shape2D.h"

class Circle : public Shape2D {
private:
	float radius;
public:
	Circle(float r) : radius(r) {} // Constructor

	void CalculateArea() override {
		area = 3.141592 * radius * radius;
	}
	float GetArea() override {
		return area;
	}
	void Scale(float scaleFactor) override {
		area = area * scaleFactor;
	}
	void ShowInfo() override {
		std::cout << GetName() << std::endl;
		std::cout << "Circle with radius: " << radius << " and area " << this->GetArea() << std::endl << std::endl;
	}
	std::string GetName() override {
		return "Circle";
	}
	bool operator>(Shape2D& other) override {
		return area > other.GetArea();
	}
	bool operator<(Shape2D& other) override {
		return area < other.GetArea();
	}
	bool operator==(Shape2D& other) override {
		return area == other.GetArea();
	}
};


#endif CIRCLE_H