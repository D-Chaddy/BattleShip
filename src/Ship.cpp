/*
 * Ship.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: Chad
 */

#include "Ship.h"
#include <string>

using namespace std;




Ship::Ship(string shipName, int shipLength, int shipRow, int shipColumn, bool isLeftRight)
{
    name = shipName;
    length = shipLength;
    row = shipRow;
    column = shipColumn;

//    for(int i = 0; i < length; i++){
//        hits.push_back(false);
//    }

    leftRight = isLeftRight;

    setLoction();

}

Ship::~Ship()
{
    // TODO Auto-generated destructor stub
}

void Ship::setLoction()
{

    if(leftRight)
    {

        for(int tempColumn = column; tempColumn < column + length; tempColumn++)
        {
            location.push_back(vector<int>{row, tempColumn});
        }

    }
    else
    {
        for(int tempRow = row; tempRow < row + length; tempRow++)
        {
            location.push_back(vector<int>{tempRow, column});
        }
    }



}

vector<vector<int>> *Ship::getLocation()
{
    return &location;
}
