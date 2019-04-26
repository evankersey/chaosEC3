#include <iostream>
#include<vector>
#include<time.h>
#include<random>
#include<fstream>

using namespace std;

const int maxWidth = 100;
const int maxHeight = 100;
bool chaosBoard[maxHeight][maxWidth] = {};

struct point
{
    int x;
    int y;
};

void initializePointsTriangle(vector<point> & startPoints)
{
    point p1;
    p1.x = 0;
    p1.y = maxWidth/2;
    startPoints.push_back(p1);

    point p2;
    p2.x = maxHeight;
    p2.y = 0;
    startPoints.push_back(p2);

    point p3;
    p3.x = maxHeight;
    p3.y = maxWidth;
    startPoints.push_back(p3);

    for(vector<point>::iterator p = startPoints.begin(); p != startPoints.end(); ++p)
    {
        cout << p->x << " " << p->y << endl;
    }
}

void initializePointsRectangle(vector<point> & startPoints){
    point p1;
    p1.x = 0;
    p1.y = 0;
    startPoints.push_back(p1);

    point p2;
    p2.x = maxHeight;
    p2.y = 0;
    startPoints.push_back(p2);

    point p3;
    p3.x = 0;
    p3.y = maxWidth;
    startPoints.push_back(p3);

    point p4;
    p4.x = maxHeight;
    p4.y = maxWidth;
    startPoints.push_back(p4);

        for(vector<point>::iterator p = startPoints.begin(); p != startPoints.end(); ++p)
    {
        cout << p->x << " " << p->y << endl;
    }
}

void initializePointsPentagon(vector<point> & startPoints){
    point p1;

}

void setPointBoardTrue(point* setPoint)
{
    chaosBoard[setPoint -> x][setPoint -> y] = true;
}

void drawGrid()
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

void drawGridEdges() //debug function, unused //prints out width and height of board to terminal
{
    for(int j=0; j<maxHeight; j++)
    {
        cout << j << " ";
    }
    cout << endl;
    for(int i=0; i<maxWidth; i++)
    {
        cout << i << " ";
        cout << endl;
    }
}//end drawGridEdges()

point* findNextPoint(point* currPoint, vector<point> startPoints)
{
    int randomPoint;
    randomPoint = rand() % startPoints.size();

    point* newPoint = new point;
    newPoint->x = (currPoint->x + startPoints[randomPoint].x)/2;
    newPoint->y = (currPoint->y + startPoints[randomPoint].y)/2;

    return newPoint;
}

void printGrid(){
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
}

int main()
{


    vector<point> startPoints;
    srand(time(NULL));

    initializePointsRectangle(startPoints);

    point* currentPoint = new point;
    currentPoint->x = rand() % maxWidth;
    currentPoint->y = rand() % maxHeight;

    for(int i=0; i<200000; i++)
    {
        setPointBoardTrue(currentPoint);
        //drawGrid();
        currentPoint = findNextPoint(currentPoint, startPoints);
    }

    printGrid();
    return 0;
}
