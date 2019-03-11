/*
 * Ship.h
 *
 *  Created on: Mar 11, 2019
 *      Author: Chad
 */

#ifndef SRC_SHIP_H_
#define SRC_SHIP_H_

#include <string>

using namespace std;

class Ship {

private:
    string name;
    int length;

public:
    Ship(string shipName, int shipLength);
    virtual ~Ship();


};

#endif /* SRC_SHIP_H_ */
