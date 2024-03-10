#pragma once
#include "Shape2D.h"
#include <iostream>
#include <cmath>

class Circle : public Shape2D {
private:
    float radius;
public:
    Circle(float r) : radius(r) { CalculateArea(); }
    void Scale(float scaleFactor) override {
        radius *= scaleFactor;
        CalculateArea();
    }
    void ShowInfo() override {
        std::cout << "� ����!" << std::endl;
        std::cout << "��� ������� = " << GetArea() << std::endl;
        std::cout << "��� ������ = " << radius << std::endl;
    }
    std::string GetName() const override { return "Circle"; }
    void CalculateArea() override {
        area = M_PI * radius * radius;
    }
};