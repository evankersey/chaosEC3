// https://github.com/evankersey/chaosEC3
// Chaos_Game
// 4/26/19
// Evan Kersey
//
// description: the chaos game creates pictures of text by jumping partway between a given set of points randomly
//      OUTPUT goes to output.txt
//
//      example output is in the outputFiles folder
//
// Special Features.
//  classes, polygon of any size, rotation of polygon, text output, option to not repeat previous node.
//
// ToDo
//  allow program to take arguments from command line
//

// completed step 10
// all step 11
// extra features


#include <iostream>
#include<vector>
#include<time.h>
#include<random>
#include<fstream>
#include<cmath>
#include"polygon.h" //calculates polygon characteristic automatically given size and rotation

using namespace std;

////////////////CHANGE THESE VARIABLES//////////
double theta = .3; //in radians
int numVertices = 5; //how many vertices the polygon has
double percentToVertex = .5; //changes where the newpoint is calculated. multiply by .5 for midpoint
bool doNotRepeatPoint = true; //
////////////////BE CAREFUL//////////////////////
//these tend to produce a good image at higher values but can also crash the program
const int maxWidth = 200;
const int maxHeight = 200;
int numIterations = 100000;
///////////////////////////////////////////////
bool chaosBoard[maxHeight][maxWidth] = {};

struct point
{
    int x;
    int y;
};

void setPointBoardTrue(point* setPoint)   //sets point on chaosBoard to true ("X ")
{
    static int nbrPointsOutOfBounds = 0;
    if ((setPoint->x > maxHeight) || (setPoint->y > maxWidth) ||
            (setPoint->x < 0) || (setPoint->y < 0))
    {
        cout << "setPointBoardTrue: " << setPoint->x << " " << setPoint->y << endl;
        nbrPointsOutOfBounds++;
        cout << "OUT OF BOUNDS! " << nbrPointsOutOfBounds << endl;
        return;
    }
    chaosBoard[setPoint -> x][setPoint -> y] = true;
}//end setBoardTrue

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

    if(doNotRepeatPoint)//disallows generating the same number twice
    {
        static int previousPoint = -1;
        do
        {
            randomPoint = rand() % startPoints.size();

        }
        while(randomPoint == previousPoint);
        previousPoint = randomPoint;
    }
    else
        randomPoint = rand() % startPoints.size(); //or just randomly selects a new point, can repeat

    point* newPoint = new point;
    newPoint->x = currPoint->x + (-currPoint->x + startPoints[randomPoint].x)*percentToVertex;
    newPoint->y = currPoint->y + (-currPoint->y + startPoints[randomPoint].y)*percentToVertex;

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
        cout << i << endl;
    }
    printGrid();
    return 0;
}


