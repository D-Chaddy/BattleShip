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
    vector<bool> hits;
    vector<vector<int>> location;
    bool leftRight;
    void setLocation();
    bool inited = false;

public:
    //Constructor and deconstructor
    Ship(string shipName, int shipLength, int row, int column, bool isLeftRight);
    Ship(string shipName, int shipLength);
    virtual ~Ship();

    vector<vector<int>>* getLocation();
    void setLocation(int shipRow, int shipColumn, bool isLeftRight);
    string getName();
    int getLength();
    bool getInited();
    void setInited(bool value);
    void setHits(int row, int column, bool value, int shipIndex);
    bool isSunk();

};

#endif /* SRC_SHIP_H_ */
