#pragma once
#include "Shape3D.h"
#include <cmath>

class Sphere : public Shape3D {
private:
    float radius;
public:
    Sphere(float r) : radius(r) { CalculateVolume(); }
    void Scale(float scaleFactor) override {
        radius *= scaleFactor;
        CalculateVolume();
    }
    void ShowInfo() override {
        std::cout << "� �����!" << std::endl;
        std::cout << "��� ����� = " << GetVolume() << std::endl;
        std::cout << "��� ������ = " << radius << std::endl;
    }
    std::string GetName() const override { return "Sphere"; }
    void CalculateVolume() override {
        volume = (4.0f / 3.0f) * M_PI * pow(radius, 3);
    }
};