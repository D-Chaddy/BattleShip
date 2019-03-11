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

using namespace std;

void printBoard(vector<vector<char>> *board);
void putValue(vector<vector<char>> *board, int row, int column, char value);
bool validInput(int row, int column);

#endif /* SRC_BATTLESHIP_H_ */
