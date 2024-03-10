#pragma once
#include "Shape3D.h"
#include "Circle.h"

class Cylinder : public Shape3D {
private:
    Circle baseCircle;
    float height;
public:
    Cylinder(float radius, float h) : baseCircle(radius), height(h) { CalculateVolume(); }
    void Scale(float scaleFactor) override {
        baseCircle.Scale(scaleFactor);
        height *= scaleFactor;
        CalculateVolume();
    }
    void ShowInfo() override {
        std::cout << "� �������!" << std::endl;
        std::cout << "��� ����� = " << GetVolume() << std::endl;
        std::cout << "������ ����� �������� = " << height << std::endl;
        baseCircle.ShowInfo();
    }
    std::string GetName() const override { return "Cylinder"; }
    void CalculateVolume() override {
        volume = baseCircle.GetArea() * height;
    }
};