#include "circle.h"





circle::circle(int maxWidth, int maxHeight)
{
    diameter = getDiameter(maxWidth, maxHeight);
    radius = diameter / 2;
    centerX = centerY = radius;

}

circle::~circle()
{
    //dtor
}



