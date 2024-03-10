#pragma once
#include <iostream>

class Shape3D {
protected:
    float volume;
public:
    virtual void CalculateVolume() = 0;
    virtual void Scale(float scaleFactor) = 0;
    virtual void ShowInfo() = 0;
    virtual std::string GetName() const = 0;
    float GetVolume() const { return volume; }
};

