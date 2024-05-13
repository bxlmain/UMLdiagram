﻿#include <iostream>
#include <string>
#include "Shape.h"
#include "Shape2D.h"
#include "Shape3D.h"
#include "Square.h"
#include "Triangle.h"
#include "Circle.h"
#include "TriangularPyramid.h"
#include "Cylinder.h"
#include "Sphere.h"

int main() {
	Square sq(3.0);
	sq.CalculateArea();
	sq.ShowInfo();

	Triangle tr(2, 5);
	tr.CalculateArea();
	tr.ShowInfo();

	Circle cr(5);
	cr.CalculateArea();
	cr.ShowInfo();

	TriangularPyramid pyramid(6, 5, 4);
	pyramid.CalculateVolume();
	pyramid.ShowInfo();

	Cylinder cyl(7, 2);
	cyl.CalculateVolume();
	cyl.ShowInfo();


	Sphere sp(4);
	sp.CalculateVolume();
	sp.ShowInfo();


	return 0;
}