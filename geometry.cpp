#include "point.h"
#include "geometry.h"
#include <cmath>


// Polygon (abstract)

int Polygon::numPolygons = 0;

int Polygon::getNumPolygons(){
    return numPolygons;
}

int Polygon::getNumSides(){
    return points.size();
}

const PointArray* Polygon::getPoints(){
    PointArray* ptr = &points;
    return ptr;
}

Polygon::Polygon(){
    numPolygons++;
}

Polygon::Polygon(const PointArray _points) :
    points(_points){
    numPolygons++;
}

Polygon::Polygon(const Point* _points, int _length) :
    points(_points, _length){
    numPolygons++;
}    



// Rectangle

Point constructorPoints[4];
Point* updateConstructorPoints(const Point& p1, const Point& p2,
			       const Point& p3, const Point& p4=Point(0, 0)){
    constructorPoints[0] = p1;
    constructorPoints[1] = p2;
    constructorPoints[2] = p3;
    constructorPoints[3] = p4;
    return constructorPoints;
}

// constructor from 4 int coordinates
// calls base class with array of Points and length
Rectangle::Rectangle(int x1, int y1, int x2, int y2) :
    Polygon(updateConstructorPoints(Point(x1, y1), 
				    Point(x1, y2),
				    Point(x2, y2), 
				    Point(x2, y1)), 4)
    {};

// constructor from 2 Points
// calls base class with array of Points and length
Rectangle::Rectangle(const Point& p1, const Point& p2) :
    Polygon(updateConstructorPoints(p1,
				    Point(p1.getX(), p2.getY()),
				    p2,
				    Point(p2.getX(), p1.getY())), 4)
    {};

double Rectangle::area() const{
    int x1 = points.get(1)->getX();
    int y1 = points.get(0)->getY();
    int x2 = points.get(2)->getX();
    int y2 = points.get(1)->getY();

    int length = y2 - y1;
    int width = x2 - x1;
    return abs((double)length * width);
}


// Triangle

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) :
    Polygon(updateConstructorPoints(p1, p2, p3), 3)
    {};

double Triangle::area() const {
    };

