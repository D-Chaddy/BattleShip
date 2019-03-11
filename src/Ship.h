/*
 * Ship.h
 *
 *  Created on: Mar 11, 2019
 *      Author: Chad
 */

#ifndef SRC_SHIP_H_
#define SRC_SHIP_H_

#include <string>
#include <vector>

using namespace std;

class Ship {

private:
    string name;
    int length;
    int row;
    int column;
    vector<bool> hits;
    vector<vector<int>> location;
    bool leftRight;
    void setLoction();

public:
    Ship(string shipName, int shipLength, int row, int column, bool isLeftRight);
    virtual ~Ship();
    vector<vector<int>> *getLocation();

};

#endif /* SRC_SHIP_H_ */
