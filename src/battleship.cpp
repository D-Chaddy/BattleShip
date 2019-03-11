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

Ship yourAircraftCarrier("Aircraft Carrier", 5);
Ship yourBattleShip("Battle Ship", 4);
Ship yourSubmarine("Submarine", 3);
Ship yourCruiser("Cruiser", 3);
Ship yourDestroyer("Destroyer", 2);

int main()
{

    printBoard(&yourBoard);

    placeShip(&yourAircraftCarrier);
    printBoard(&yourBoard);

    placeShip(&yourBattleShip);
    printBoard(&yourBoard);

    placeShip(&yourSubmarine);
    printBoard(&yourBoard);

    placeShip(&yourCruiser);
    printBoard(&yourBoard);

    placeShip(&yourDestroyer);
    printBoard(&yourBoard);

    while(true)
    {





        //tempShip.setLocation(1, 1);

        for(unsigned int i = 0; i < yourAircraftCarrier.getLocation()->size(); i++)
        {
            putValue(&yourBoard, yourAircraftCarrier.getLocation()->at(i).at(0), yourAircraftCarrier.getLocation()->at(i).at(1), '#');
        }

        printBoard(&theirBoard);
        printBoard(&yourBoard);

        string input;
        cout << "Enter location: ";
        cin >> input;
        cout << endl;
        putValue(&theirBoard, getInput(input)[0], getInput(input)[1], '*');

    }

    return 0;

}

vector<int> getInput(string input)
{
    vector<int> temp{input[0] - 'A', atoi(input.substr(1).c_str()) - 1};
    return temp;
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

void placeShip(Ship *ship)
{
    string locationTemp;
    bool rightLeftTemp;

    cout << "Location of " << ship->getName() << " (" << ship ->getLength() << " spaces): ";
    cin >> locationTemp;
    cout << "0 for up and down. 1 for left and right: ";
    cin >> rightLeftTemp;

    ship->setLocation(getInput(locationTemp)[0], getInput(locationTemp)[1], rightLeftTemp);

    printShip(ship);
}

void printShip(Ship *ship)
{
    for(unsigned int i = 0; i < ship->getLocation()->size(); i++)
    {
        putValue(&yourBoard, ship->getLocation()->at(i).at(0), ship->getLocation()->at(i).at(1), '#');
    }
}
