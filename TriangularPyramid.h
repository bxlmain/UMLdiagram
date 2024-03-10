#pragma once
#include "Shape3D.h"
#include "Triangle.h"

class TriangularPyramid : public Shape3D {
private:
    Triangle baseTriangle;
    float height;
public:
    TriangularPyramid(float base, float height, float pyramidHeight) : baseTriangle(base, height), height(pyramidHeight) {
        CalculateVolume();
    }
    void Scale(float scaleFactor) override {
        baseTriangle.Scale(scaleFactor);
        height *= scaleFactor;
        CalculateVolume();
    }
    void ShowInfo() override {
        std::cout << "Я треугольная пирамида!" << std::endl;
        std::cout << "Мой объем = " << GetVolume() << std::endl;
        std::cout << "Высота моей пирамиды = " << height << std::endl;
        baseTriangle.ShowInfo();
    }
    std::string GetName() const override { return "TriangularPyramid"; }
    void CalculateVolume() override {
        volume = (baseTriangle.GetArea() * height) / 3.0f;
    }
};