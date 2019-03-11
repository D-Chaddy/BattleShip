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
    void setLocation();

public:
    Ship(string shipName, int shipLength, int row, int column, bool isLeftRight);
    Ship(string shipName, int shipLength);
    virtual ~Ship();
    vector<vector<int>> *getLocation();
    void setLocation(int shipRow, int shipColumn, bool isLeftRight);

};

#endif /* SRC_SHIP_H_ */
