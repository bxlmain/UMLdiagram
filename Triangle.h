#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <iostream>
#include <string>
#include "Shape2D.h"

class Triangle : public Shape2D {
private:
	float base;
	float height;
public:
	Triangle(float b, float h) : base(b), height(h) {} // Constructor

	void CalculateArea() override {
		area = 0.5 * base * height;
	}
	float GetArea() override {
		return area;
	}
	void Scale(float scaleFactor) override { area = area * scaleFactor; }
	void ShowInfo() override {
		std::cout << GetName() << std::endl;
		std::cout << "Triangle with base: " << base << " and height: " << height << " and area " << this->GetArea() << std::endl << std::endl;
	}
	std::string GetName() override {
		return "Triangle";
	}
	bool operator>(Shape2D& other) override { return area > other.GetArea(); }
	bool operator<(Shape2D& other) override { return area < other.GetArea(); }
	bool operator==(Shape2D& other) override { return area == other.GetArea(); }
};

#endif TRIANGLE_H