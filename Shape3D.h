#ifndef SHAPE3D_H
#define SHAPE3D_H
#include <string>
#include "Shape.h"

class Shape3D : public Shape {
protected:
	float volume;
public:
	virtual float GetVolume() = 0;
	virtual bool operator>(Shape3D& other) = 0;
	virtual bool operator<(Shape3D& other) = 0;
	virtual bool operator==(Shape3D& other) = 0;
	virtual void CalculateVolume() = 0;
};

#endif SHAPE3D_H
