#ifndef SHAPE2D_H
#define SHAPE2D_H
#include <string>
#include "Shape.h"

class Shape2D : public Shape {
protected:
	float area;
public:
	virtual float GetArea() = 0;
	virtual bool operator>(Shape2D& other) = 0;
	virtual bool operator<(Shape2D& other) = 0;
	virtual bool operator==(Shape2D& other) = 0;
	virtual void CalculateArea() = 0;
};

#endif SHAPE2D_H