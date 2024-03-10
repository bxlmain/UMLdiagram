#include "Circle.h"
#include "Shape3D.h"
#include "TriangularPyramid.h"
#include "Cylinder.h"
#include "Sphere.h"
#include "Triangle.h"
#include "Shape2D.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Shape {
public:
    virtual void Scale(float scaleFactor) = 0;
    virtual void ShowInfo() = 0;
    virtual string GetName() = 0;
};


class Shape2D : public Shape {
protected:
    float area = 0;

public:
    virtual float GetArea() { return area; }

    virtual void CalculateArea() = 0; 

    bool operator>(const Shape2D& rhs) { return this->area > rhs.area; }
    bool operator<(const Shape2D& rhs) { return this->area < rhs.area; }
    bool operator==(const Shape2D& rhs) { return this->area == rhs.area; }
};


class Shape3D : public Shape 
{
protected:
    float volume;
public:
    virtual void CalculateVolume() = 0;
    virtual void Scale(float scaleFactor) = 0;
    virtual void ShowInfo() = 0;
    virtual string GetName() const = 0;
    float GetVolume() const { return volume; }
};


class Square : public Shape2D 
{
protected:
    float side;

public:
    void Scale(float scaleFactor) override 
    {
        side *= scaleFactor;
        CalculateArea();
    }

    void ShowInfo() override 
    {
        cout << "Square with side length " << side << endl;
    }

    string GetName() override 
    {
        return "Square";
    }

    void CalculateArea() override 
    {
        area = side * side;
    }
};

class Triangle : public Shape2D 
{
protected:
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
        cout << "Я треугольник!" << endl;
        cout << "Моя площадь = " << GetArea() << endl;
        cout << "Длина моего основания = " << base << endl;
        cout << "Моя высота = " << height << endl;
    }
    string GetName() const override { return "Triangle"; }
    void CalculateArea() override {
        area = 0.5f * base * height;
    }
};

class Circle : public Shape2D 
{
protected:
    float radius;
public:
    Circle(float r) : radius(r) { CalculateArea(); }
    void Scale(float scaleFactor) override {
        radius *= scaleFactor;
        CalculateArea();
    }
    void ShowInfo() override {
        cout << "Я круг!" << endl;
        cout << "Моя площадь = " << GetArea() << endl;
        cout << "Мой радиус = " << radius << endl;
    }
    string GetName() const override { return "Circle"; }
    void CalculateArea() override {
        area = M_PI * radius * radius;
    }
};


class TriangularPyramid : public Shape3D 
{
protected:
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
        cout << "Я треугольная пирамида!" << endl;
        cout << "Мой объем = " << GetVolume() << endl;
        cout << "Высота моей пирамиды = " << height << endl;
        baseTriangle.ShowInfo();
    }
    string GetName() const override { return "TriangularPyramid"; }
    void CalculateVolume() override {
        volume = (baseTriangle.GetArea() * height) / 3.0f;
    }
};

class Cylinder : public Shape3D 
{
protected:
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
        cout << "Я цилиндр!" << endl;
        cout << "Мой объем = " << GetVolume() << endl;
        cout << "Высота моего цилиндра = " << height << endl;
        baseCircle.ShowInfo();
    }
    string GetName() const override { return "Cylinder"; }
    void CalculateVolume() override {
        volume = baseCircle.GetArea() * height;
    }
};

class Sphere : public Shape3D {
private:
    float radius;
public:
    Sphere(float r) : radius(r) { CalculateVolume(); }
    void Scale(float scaleFactor) override {
        radius *= scaleFactor;
        CalculateVolume();
    }
    void ShowInfo() override 
    {
        cout << "Я сфера!" << endl;
        cout << "Мой объем = " << GetVolume() << endl;
        cout << "Мой радиус = " << radius << endl;
    }
    string GetName() const override { return "Sphere"; }
    void CalculateVolume() override {
        volume = (4.0f / 3.0f) * M_PI * pow(radius, 3);
    }
};

int main() 
{
    
    Circle circle(5.0f); 
    Triangle triangle(3.0f, 4.0f); 
    Cylinder cylinder(3.0f, 7.0f); 
    Sphere sphere(4.0f); 
    TriangularPyramid pyramid(3.0f, 4.0f, 6.0f); 

    
    circle.Scale(2.0f);
    triangle.Scale(1.5f);
    cylinder.Scale(0.5f);
    sphere.Scale(1.2f);
    pyramid.Scale(2.0f);

  
    cout << "После масштабирования:" << endl;

    cout << "\nКруг:" << endl;
    circle.ShowInfo();

    cout << "\nТреугольник:" << endl;
    triangle.ShowInfo();

    cout << "\nЦилиндр:" << endl;
    cylinder.ShowInfo();

    cout << "\nСфера:" << endl;
    sphere.ShowInfo();

    cout << "\nТреугольная пирамида:" << endl;
    pyramid.ShowInfo();

    return 0;
}