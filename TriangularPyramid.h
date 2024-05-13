#ifndef TRIANGULARPYRAMID_H
#define TRIANGULARPYRAMID_H
#include <iostream>
#include <string>
#include "Shape3D.h"
#include "Triangle.h"

class TriangularPyramid : public Shape3D {
private:
	float triangleHeight;
	Triangle baseTriangle;
public:
	TriangularPyramid(float triangleHeight, float base, float height) : triangleHeight(triangleHeight), baseTriangle(base, height) {} // Constructor

	void CalculateVolume() override {
		baseTriangle.CalculateArea();
		volume = (1.0 / 3.0) * baseTriangle.GetArea() * triangleHeight;
	}
	float GetVolume() override {
		return volume;
	}
	void Scale(float scaleFactor) override {
		volume = volume * scaleFactor;
	}
	void ShowInfo() override {
		CalculateVolume();
		std::cout << GetName() << std::endl;
		std::cout << "TriangularPyramid with height: " << triangleHeight << " and volume: " << this->GetVolume() << std::endl << std::endl;
	}
	std::string GetName() override {
		return "TriangularPyramid";
	}
	bool operator>(Shape3D& other) override { return volume > other.GetVolume(); }
	bool operator<(Shape3D& other) override { return volume < other.GetVolume(); }
	bool operator==(Shape3D& other) override { return volume == other.GetVolume(); }
};

#endif TRIANGULARPYRAMID_H