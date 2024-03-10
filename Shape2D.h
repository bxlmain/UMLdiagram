#pragma once
#include <iostream>

class Shape2D {
protected:
    float area;
public:
    virtual void CalculateArea() = 0;
    virtual void Scale(float scaleFactor) = 0;
    virtual void ShowInfo() = 0;
    virtual std::string GetName() const = 0;
    float GetArea() const { return area; }
};
