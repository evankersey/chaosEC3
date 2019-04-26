#ifndef POLYGON_H
#define POLYGON_H

#include<vector>
#include<cmath>

class polygon
{

public:
    struct point
    {
        int x;
        int y;
    };
    polygon(int, double, double, double);
    virtual ~polygon();
    std::vector<point> vertices;


protected:

private:
    const double pi = 3.14159265359;
    double radius;
    double centerX;
    double centerY;
    double diameter;
    void makeCircle(int);
    void findPolygonPoints(double, double, double);
    double maxWidth;
    double maxHeight;
    double numSides;


};

#endif // POLYGON_H
