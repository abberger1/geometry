#include "point.h"
#include "geometry.h"


int main()
{
    int num_points = 10;
    Point* points = new Point [num_points];
    for (int x=0; x<num_points; x++){
	Point& point = points[x];
	point.setX(x);
	point.setY(x * 2);
    }

    PointArray point_array(points, num_points);

    // test Rectangle contructor (x1, y1, x2, y2)
    Rectangle rect_from_points(0, 0, 5, 20);

    // test Rectangle area
    cout << "Rectangle Area: " << rect_from_points.area() << endl;


    delete [] points;
    return 0;
}
