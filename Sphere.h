#ifndef SPHERE_H
#define SPHERE_H
#include <iostream>
#include <string>
#include "Shape3D.h"

class Sphere : public Shape3D {
private:
	float radius;
public:
	Sphere(float r) : radius(r) {} // Constructor

	float GetVolume() override {
		return volume;
	}
	void Scale(float scaleFactor) override {
		volume = volume * scaleFactor;
	}
	void ShowInfo() override {
		std::cout << GetName() << std::endl;
		std::cout << "Sphere with radius: " << radius << " and volume: " << GetVolume() << std::endl;
	}
	std::string GetName() override {
		return "Sphere";
	}
	bool operator>(Shape3D& other) override {
		return volume > other.GetVolume();
	}
	bool operator<(Shape3D& other) override {
		return volume < other.GetVolume();
	}
	bool operator==(Shape3D& other) override { return volume == other.GetVolume(); }
	void CalculateVolume() override {
		volume = (4.0 / 3.0) * 3.141592 * radius * radius * radius;
	}
};

#endif SPHERE_H