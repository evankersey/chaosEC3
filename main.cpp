// https://github.com/evankersey/chaosEC3
// Chaos_Game
// 4/26/19
// Evan Kersey
//
// description: the chaos game creates pictures of text by jumping partway between a given set of points randomly
//
// Special Features.
//  classes, polygon of any size, rotation of polygon, text output, etc...
//
// ToDo
//  allow program to take arguments from command line
//  do not repeat previous node

#include <iostream>
#include<vector>
#include<time.h>
#include<random>
#include<fstream>
#include<cmath>
#include"polygon.h" //calculates polygon characteristic automatically given size and rotation

using namespace std;

////////////////CHANGE THESE VARIABLES//////////
double theta = 0; //in radians
int numVertices = 5; //how many vertices the polygon has
double divideByMe = 2.5; //changes where the newpoint is calculated. divide by two for midpoint
////////////////BE CAREFUL//////////////////////
const int maxWidth = 150;
const int maxHeight = 150;
int numIterations = 2000000;
///////////////////////////////////////////////
bool chaosBoard[maxHeight][maxWidth] = {};

struct point
{
    int x;
    int y;
};

void setPointBoardTrue(point* setPoint) //sets point on chaosBoard to true ("X ")
{
    chaosBoard[setPoint -> x][setPoint -> y] = true;
}

void drawGrid()//prints grid to terminal
{
    for(int i=0; i<maxWidth; i++)
    {
        for(int j=0; j<maxHeight; j++)
        {
            if(chaosBoard[i][j] == true)
            {
                cout << "X ";
            }
            else cout << "  ";
        }
        cout << endl;
    }
}//end drawGrid

point* findNextPoint(point* currPoint, vector<polygon::point> startPoints) //finds next point to print. randomly picks a startpoint and moves halfway to it
{
    int randomPoint;
    randomPoint = rand() % startPoints.size();

    point* newPoint = new point;
    newPoint->x = (currPoint->x + startPoints[randomPoint].x)/divideByMe;
    newPoint->y = (currPoint->y + startPoints[randomPoint].y)/divideByMe;

    return newPoint;
}//end find Next Point

void printGrid()//prints grid to outputFile
{
    ofstream outputFile;
    outputFile.open("output.txt");
    for(int i=0; i<maxWidth; i++)
    {
        for(int j=0; j<maxHeight; j++)
        {
            if(chaosBoard[i][j] == true)
            {
                outputFile << "X ";
            }
            else outputFile << "  ";
        }
        outputFile << endl;
    }
    outputFile.close();
}//end printGrid

int main()
{
    srand(time(NULL)); //random seed

    point* currentPoint = new point; //random startPoint
    currentPoint->x = rand() % maxWidth;
    currentPoint->y = rand() % maxHeight;

    polygon myPolygon(numVertices, theta, maxWidth, maxHeight); //creates polygon class object // Special Features.
    std::cout << myPolygon.vertices[0].x << endl;; //prints list off vertex coords to terminal

    for(int i=0; i<numIterations; i++) //higher number = higher resolution image
    {
        setPointBoardTrue(currentPoint);
        //drawGrid();
        currentPoint = findNextPoint(currentPoint, myPolygon.vertices);
    }
    printGrid();
    return 0;
}


