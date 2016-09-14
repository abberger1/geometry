#include "point.h"

Point::Point(int _x, int _y) : x(_x), y(_y) {};
Point::~Point(){};

int Point::getX() const{
    return x;
}

int Point::getY() const{
    return y;
}

void Point::setX(const int new_x){
    x = new_x;
}

void Point::setY(const int new_y){
    y = new_y;
}

PointArray::PointArray(){
    length = 0;
    point = new Point [length];
}

PointArray::PointArray(const PointArray& pv){
    point = new Point [pv.length];
    length = pv.length;
    for (int x=0; x<pv.length; x++){
	point[x] = pv.point[x];
    }
}

PointArray::PointArray(const Point* points, const int size) : length(size) {
    point = new Point [size];
    length = size;
    for (int x=0; x<length; x++){
	point[x] = points[x];
    }
}

void PointArray::display(){
    for (int x=0; x<length; x++){
	cout << "<" << x << "> ";
	cout << "(" << point[x].getX() << ", ";
	cout <<  point[x].getY() << ") " << endl;
    }
}

PointArray::~PointArray(){
    delete [] point;
}

int PointArray::size(){
    return length;
}

void PointArray::clear(){
    resize(0);
}

void PointArray::append(const Point p){
    resize(length+1);
    point[length-1] = p;
}

void PointArray::resize(int size){
    Point* pt = new Point [size];
    for (int x=0; x<size; x++){
	pt[x] = point[x];
    }
    delete [] point;
    point = pt;
    length = size;
}

void PointArray::insert(const int position, const Point& p){
    resize(length + 1);
    for (int x=length-1; x>position; x--){
	point[x] = point[x - 1];
    }
    point[position] = p;
}

void PointArray::remove(const int position){
    if (position >= 0 and position < length){
	for (int x=position; x<length-1; x++){
	    point[x] = point[x + 1];
	}
    }
    resize(length - 1);
}

Point* PointArray::get(const int position){
    return position < length && position >= 0 ? point + position : NULL;
}

const Point* PointArray::get(const int position) const{
    return position < length && position >= 0 ? point + position : NULL;
}

//long double PointArray::mean(){
//    long double sum = 0;
//    for (int x=0; x<length; x++){
//	sum = sum + point[x];
//    }
//    long double mean = sum / length;
//    return mean;
//}
