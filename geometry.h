#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "point.h"


class Polygon
{
    protected:
	static int numPolygons;
	PointArray points;
    public:
	Polygon();	
	Polygon(const PointArray _points);
	Polygon(const Point* _points, int _length);
	~Polygon(){ --numPolygons; };
	int getNumSides();
	static int getNumPolygons();
	const PointArray* getPoints(); 
	virtual double area() const = 0;
};	


class Rectangle : public Polygon
{
    public:
	Rectangle(int x1, int x2, int y1, int y2);
	Rectangle(const Point& p1, const Point& p2);
	double area() const;
};


class Triangle : public Polygon
{
    public:
	Triangle(const Point& p1, const Point& p2, const Point& p3);
	double area() const;
};
#endif
