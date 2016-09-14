#ifndef POINT_H
#define POINT_H

#include <iostream>
using namespace std;


class Point
{
    private:
	int x;
	int y;
    public:
	Point(int _x=0, int _y=0);
	~Point();
	int getX() const;
	int getY() const;
	void setX(const int new_x);
	void setY(const int new_y);
};


class PointArray
{
    private:
	Point* point;
	int length;
	void resize(int size);
    public:
	PointArray();
	PointArray(const PointArray& pv);
	PointArray(const Point* points, const int size);
	~PointArray();
	int size();
	void clear();
	void display();
	void append(const Point p);
	void insert(const int position, const Point& p);
	void remove(const int position);
	Point* get(const int position);
	const Point* get(const int position) const;
	//long double mean();
};
#endif
