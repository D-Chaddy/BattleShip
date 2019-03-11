/*
 * Ship.cpp
 *
 *  Created on: Mar 11, 2019
 *      Author: Chad
 */

#include "Ship.h"
#include <string>

using namespace std;




Ship::Ship(string shipName, int shipLength)
{
    name = shipName;
    length = shipLength;
}

Ship::~Ship()
{
    // TODO Auto-generated destructor stub
}

