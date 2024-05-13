#ifndef CYLINDER_H
#define CYLINDER_H
#include <iostream>
#include <string>
#include "Shape3D.h"
#include "Circle.h"


class Cylinder : public Shape3D {
private:
	float height;
	Circle baseCircle;
public:
	Cylinder(float h, float r) : height(h), baseCircle(r) {} // Constructor
	void CalculateVolume() override {
		baseCircle.CalculateArea();
		volume = baseCircle.GetArea() * height;
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
		std::cout << "Cylinder with height:" << height << " and volume: " << GetVolume() << std::endl << std::endl;
	}
	std::string GetName() override {
		return "Cylinder";
	}
	bool operator>(Shape3D& other) override { return volume > other.GetVolume(); }
	bool operator<(Shape3D& other) override { return volume < other.GetVolume(); }
	bool operator==(Shape3D& other) override { return volume == other.GetVolume(); }
};
#endif CYLINDER_H