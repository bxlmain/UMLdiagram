#ifndef SQUARE_H
#define SQUARE_H
#include <iostream>
#include <string>
#include "Shape2D.h"

class Square :public Shape2D {
private:
	float side;
public:
	Square(float s) :side(s) {} //Constructor

	float GetArea() override {
		return area;
	}
	void Scale(float scaleFactor) override {
		area = area * scaleFactor;
	}
	void ShowInfo() override {
		std::cout << GetName() << std::endl;
		std::cout << "side: " << side << std::endl;
		std::cout << "area: " << GetArea() << std::endl << std::endl;
	}
	std::string GetName() override {
		return "Square";
	}
	bool operator>(Shape2D& other) override { return area > other.GetArea(); }
	bool operator<(Shape2D& other) override { return area < other.GetArea(); }
	bool operator==(Shape2D& other) override { return area == other.GetArea(); }
	void CalculateArea() override {
		area = side * side;
	}
};


#endif SQUARE_H
