/*
 * battleship.h
 *
 *  Created on: Mar 10, 2019
 *      Author: Chad
 */

#ifndef SRC_BATTLESHIP_H_
#define SRC_BATTLESHIP_H_

#include <vector>
#include <iostream>
#include "Ship.h"

using namespace std;

void printBoard(vector<vector<char>> *board);
void putValue(vector<vector<char>> *board, int row, int column, char value);
bool validInput(int row, int column);
vector<int> getInput(string input);
void printShips(vector<vector<char>> *board, vector<Ship*> *ships);
void placeShip(vector<Ship*> *ships, int index);
void printOptions(vector<Ship*> *ships);
void placeShipComp(vector<Ship*> *ships, int index, string location, bool rightLeft);
void fire(vector<vector<char>> *board, vector<Ship*> *ships, int row, int column);
bool gameOver(vector<Ship*> *yourShips, vector<Ship*> *theirShips);
void compFire(vector<vector<char>> *board);

#endif /* SRC_BATTLESHIP_H_ */
