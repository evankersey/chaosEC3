#include "polygon.h"

#include<cmath>
#include<iostream>
// finds the vertices of a polygon of size n
// first finds the largest circle that can be made based on size settings
// equation divedes circle into n portions where the begining of each portion is a vertex (see /chaosEC3/polygonCircleVisual.png for visual)
// these points are stored in a public vector

void polygon::findPolygonPoints(double maxHeight, double maxWidth, double theta) //calculates vertices of polygon of size n
{
    //x[n] = r * cos(2*pi*n/N + theta) + x_centre
    //y[n] = r * sin(2*pi*n/N + theta) + y_centre

    point defaultPoint;
    defaultPoint.x = 0;
    defaultPoint.y = 0;

    double num;
    std::cout << "numSides: " << numSides << std::endl;
    for(int n=0; n < numSides; n++)
    {
        num = n;
        defaultPoint.x = radius * cos((2.0*pi*num)/numSides + theta) + centerX;
        defaultPoint.y = radius * sin((2.0*pi*num)/numSides + theta) + centerY;
        vertices.push_back(defaultPoint);
        std::cout << defaultPoint.x << " " << defaultPoint.y << std::endl;

    }

}

double getDiameter(double maxWidth, double maxHeight)
{
    if(maxWidth>=maxHeight)
        return maxWidth;
    else
        return maxHeight;
}

void polygon::makeCircle(int diameter)
{

    radius = diameter / 2;
    centerX = centerY = radius;
}


polygon::polygon(int numberSides, double theta, double maxWidth, double maxHeight)
{
    numSides = numberSides;
    diameter = getDiameter(maxWidth, maxHeight);

    makeCircle(diameter);

    findPolygonPoints(maxHeight, maxWidth, theta);
}

polygon::~polygon()
{
    //dtor
}
