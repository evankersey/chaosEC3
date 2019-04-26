#ifndef CIRCLE_H
#define CIRCLE_H


class circle
{
public:
    circle(int maxWidth, int maxHeight);
    virtual ~circle();
    int centerX;
    int centerY;
    int radius;
    const double pi = 3.14159265359;


protected:

private:

    int diameter;

};

#endif // CIRCLE_H



