/*
 * Name: Chris Caldwell
 * Date Submitted:
 * Lab Section: 003
 * Assignment Name: Lab 3: Finding Groups Using Recursion
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <fstream>
#include <assert.h>

using namespace std;

//Represents an occupied square in the grid
//Do not modify the GridSquare class or its member functions
class GridSquare
{
    private:
        int row, col;
    public:
        GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square
        GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square
        //Compare with == operator, used in test cases
        bool operator== (const GridSquare r) const
        {
            if ((row == r.row) && (col == r.col))
            {
                return true;
            }
            return false;
        }
        int getRow() { return row; } //return row value
        int getCol() { return col; } //return column value
        //Output using << operator, used in Grouping::printGroups()
        friend ostream& operator<< (ostream& os, const GridSquare obj);
};

//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

/*
Groups squares in 10x10 grid upon construction
Additional private helper functions may be added
Need to implement the constructor that takes a file name
as well as findGroup
The findGroup function's parameter list may be changed based
on how the function is implemented
*/
class Grouping
{
    private:
        int grid[10][10];
        vector<vector<GridSquare>> groups;
        bool isGroup(int r, int c);
    public:
        Grouping() : grid{},groups() {} //Default constructor, no groups
        Grouping(string fileName); //Implement this function
        void findGroup(int r, int c); //Implement this function (recursive)
        void printGroups() //Displays grid's groups of squares
        {
            for(int g=0; g<groups.size(); g++)
            {
                cout << "Group " << g+1 << ": ";
                for(int s=0; s<groups[g].size(); s++)
                {
                    cout << " " << groups[g][s];
                }
                cout << endl;
            }
        }
        vector<vector<GridSquare>> getGroups() //Needed in unit tests
        {
            return groups;
        }
};

//Implement the (parameterized) constructor and findGroup functions below
Grouping::Grouping(string fileName){
    char inChar;
    int i, j, vecR;
    //Open file from parameter and ensure it's valid
    ifstream inFile(fileName);
    assert(inFile.good());
    
    //Store input file to grid[][] as 1's and 0's
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            inFile >> inChar;
            if(inChar == 'X'){
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }

    inFile.close();

    //Iterate through grid[][] to find groups,
    //then call recursive function findGroup()
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            if(grid[i][j] == 1 && !isGroup(i, j)){  //if not in group, call findGroup()
                //cout<<"Is running\n";
                //cout<<"";
                groups.push_back(vector<GridSquare>());
                findGroup(i, j);
            }
        }
    }
}

//Added parameters for indecies of 2D vector
void Grouping::findGroup(int r, int c){
    //Base case
    if(isGroup(r, c)) return;

    //If not in a group, add to group
    groups.back().push_back(GridSquare(r, c));

    //Check other cases
    //Square is 0
    if(grid[r][c] == 0) return;
    //Check North
    if(r > 0 && grid[r-1][c] == 1){
        findGroup(r-1, c);
    }
    //Check East
    if(c < 9 && grid[r][c+1] == 1){
        findGroup(r, c+1);
    }
    //Check South
    if(r < 9 && grid[r+1][c] == 1){
        findGroup(r+1, c);
    }
    //Check West
    if(c > 0 && grid[r][c-1] == 1){
        findGroup(r, c-1);
    }
}

bool Grouping::isGroup(int r, int c){
    //Iterate through the 2D vector groups to ensure (r,c) is not grouped
    for(int i = 0; i < groups.size(); i++){
        for(int j = 0; j < groups[i].size(); j++){
            if(groups[i][j].getRow() == r && groups[i][j].getCol() == c){
                //cout<<groups[i][j].getRow()<<" == "<<r<<" ... "<<groups[i][j].getCol()<<" == "<<c<<"\n";
                return true;
            }
        }
    } 

    return false;
}

//Simple main function to test Grouping
int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();
    
    return 0;
}