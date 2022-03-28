/*
 * Name: Chris Caldwell
 * Date Submitted: 3/19/22
 * Lab Section: 003
 * Assignment Name: Finding the Closest Pair of Points
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    double x;
    double y;
};

//Helper function for finding distance b/w 2 points
double calcDist(point, point);

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/
double closestPair(string filename){
    vector<vector<vector<point>>> grid;
    fstream in(filename);
    point pnt = {-1, -1};
    int i, j, k, h;
    int numPts, b;
    int posX, posY;
    double interval;
    double minDist = 1, dist;
  
    //Read in num. of values and calculate b
    //b is set to the floor of the root of how many values there are,
    //this allows for an easily-navigated perfect square of point vectors
    in >> numPts;
    b = floor(sqrt(numPts));
    //b = numPts - (numPts % 3);
    interval = 1.0/b;

    //Fill the struct with -1 (out of bounds for valid points)
    for(i = 0; i < b; i++){
        grid.push_back(vector<vector<point>>());
        for(j = 0; j < b; j++){
            grid[i].push_back(vector<point>());
            grid[i][j].push_back(pnt);
        }
    }

    //Hash the points to the 2D vector of point vectors
    for(i = 0; i < numPts; i++){
        in >> pnt.x;
        in >> pnt.y;
        posX = pnt.x/interval;
        posY = pnt.y/interval;
        if(grid[posX][posY][0].x != -1){
            grid[posX][posY].push_back(pnt);
        } else {
            grid[posX][posY].at(0) = pnt;
        }
    }

    in.close();

    for(i = 0; i < b; i++){
        for(j = 0; j < b; j++){
            for(k = 0; k < grid.at(i).at(j).size(); k++){
                //Check that cell is not "empty"
                if(grid.at(i).at(j).at(k).x != -1){
                    //Compare amongst points within cell
                    for(h = k + 1; h < grid.at(i).at(j).size(); h++){
                        dist = calcDist(grid.at(i).at(j).at(k), grid.at(i).at(j).at(h));
                        if(dist < minDist){minDist = dist;}
                    }
                    //Compare to nearby cells
                    //Right cell
                    try{
                        for(h = 0; h < grid.at(i).at(j+1).size(); h++){
                            dist = calcDist(grid.at(i).at(j).at(k), grid.at(i).at(j+1).at(h));
                            if(dist < minDist){minDist = dist;}
                        }
                    }catch(const out_of_range e1){}
                    //Lower left cell
                    try{
                        for(h = 0; h < grid.at(i+1).at(j-1).size(); h++){
                            dist = calcDist(grid.at(i).at(j).at(k), grid.at(i+1).at(j-1).at(h));
                            if(dist < minDist){minDist = dist;}
                        }
                    }catch(const out_of_range e2){}
                    //Lower cell
                    try{
                        for(h = 0; h < grid.at(i+1).at(j).size(); h++){
                            dist = calcDist(grid.at(i).at(j).at(k), grid.at(i+1).at(j).at(h));
                            if(dist < minDist){minDist = dist;}
                        }
                    }catch(const out_of_range e3){}
                    //Lower right cell
                    try{
                        for(h = 0; h < grid.at(i+1).at(j+1).size(); h++){
                            dist = calcDist(grid.at(i).at(j).at(k), grid.at(i+1).at(j+1).at(h));
                            if(dist < minDist){minDist = dist;}
                        }
                    }catch(const out_of_range e4){}
                }
            }
        }
    }

    return minDist;
}

double calcDist(point p1, point p2){
    return sqrt(pow(p1.x - p2.x, 2.0) + pow(p1.y - p2.y, 2.0));
}

int main()
{
    double min;
    string filename;
    cout << "File with list of points within unit square: ";
    cin >> filename;
    min = closestPair(filename);
    cout << setprecision(16);
    cout << "Distance between closest pair of points: " << min << endl;
    return 0;
}