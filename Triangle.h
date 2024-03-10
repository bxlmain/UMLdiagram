#pragma once
#include "Shape2D.h"
#include <iostream>
#include <string>

class Triangle : public Shape2D {
private:
    float base;
    float height;
public:
    Triangle(float b, float h) : base(b), height(h) { CalculateArea(); }
    void Scale(float scaleFactor) override {
        base *= scaleFactor;
        height *= scaleFactor;
        CalculateArea();
    }
    void ShowInfo() override {
        std::cout << "� �����������!" << std::endl;
        std::cout << "��� ������� = " << GetArea() << std::endl;
        std::cout << "����� ����� ��������� = " << base << std::endl;
        std::cout << "��� ������ = " << height << std::endl;
    }
    std::string GetName() const override { return "Triangle"; }
    void CalculateArea() override {
        area = 0.5f * base * height;
    }
};