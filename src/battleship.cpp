/*
 * battleship.cpp
 *
 *  Created on: Mar 10, 2019
 *      Author: Chad
 */

#include "battleship.h"
#include <iostream>
#include <vector>
#include <string>
#include "Ship.h"

using namespace std;

int rows = 10;
int columns = 10;

vector<vector<char>> yourBoard(rows, vector<char> (columns, 'O'));
vector<vector<char>> theirBoard(rows, vector<char> (columns, 'O'));

vector<Ship> yourShips;
vector<Ship> theirShips;

Ship tempShip("Temp Ship", 3, 1, 1, false);

int main()
{

    while(true)
    {



        for(unsigned int i = 0; i < tempShip.getLocation()->size(); i++)
        {
            putValue(&yourBoard, tempShip.getLocation()->at(i).at(0), tempShip.getLocation()->at(i).at(1), 'T');
        }

        printBoard(&theirBoard);
        printBoard(&yourBoard);

        //cout << tempShip.getLocation()->at(0).at(0) << tempShip.getLocation()->at(0).at(1);
        //cout << tempShip.getLocation()->at(0).at(1);

        string input;
        cout << "Enter location: ";
        cin >> input;
        cout << endl;
        putValue(&theirBoard, input[0] - 'A', atoi(input.substr(1).c_str()) - 1, '*');

    }

    return 0;

}

void printBoard(vector<vector<char>> *board)
{

    char rowLetters[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

    cout << "\t";

    for(int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }

    cout << endl;

    for(unsigned int row = 0; row < board->size(); row++)
    {

        cout << rowLetters[row] << "\t";

        for(unsigned int column = 0; column < board[0].size(); column++)
        {
            cout << board->at(row).at(column) << "\t";
        }

        cout << endl;

    }

    cout << endl;

}

void putValue(vector<vector<char>> *board, int row, int column, char value)
{
    if(validInput(row, column))
    {
        board->at(row).at(column) = value;
    }
    else
    {
        cout << "INVALID CHOICE" << endl;
    }

}

bool validInput(int row, int column)
{
    return (row < rows && row >= 0) &&  (column < columns && column >= 0);
}
