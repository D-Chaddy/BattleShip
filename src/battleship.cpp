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
#include <conio.h>

using namespace std;

int rows = 10;
int columns = 10;

vector<vector<char>> yourBoard(rows, vector<char> (columns, 'O'));
vector<vector<char>> theirBoard(rows, vector<char> (columns, 'O'));

Ship yourAircraftCarrier("Aircraft Carrier", 5);
Ship yourBattleShip("Battle Ship", 4);
Ship yourSubmarine("Submarine", 3);
Ship yourCruiser("Cruiser", 3);
Ship yourDestroyer("Destroyer", 2);

vector<Ship*> ships{&yourAircraftCarrier, &yourBattleShip, &yourSubmarine, &yourCruiser, &yourDestroyer};

int main()
{

    while(!yourAircraftCarrier.getInited() ||
          !yourBattleShip.getInited() ||
          !yourSubmarine.getInited() ||
          !yourCruiser.getInited() ||
          !yourDestroyer.getInited())
    {

        printBoard(&yourBoard);

        int input;
        printOptions(&yourAircraftCarrier, &yourBattleShip, &yourSubmarine, &yourCruiser, &yourDestroyer);
        cin >> input;
        switch(input)
        {
            case 1:
                placeShip(&yourAircraftCarrier);
                break;
            case 2:
                placeShip(&yourBattleShip);
                break;
            case 3:
                placeShip(&yourSubmarine);
                break;
            case 4:
                placeShip(&yourCruiser);
                break;
            case 5:
                placeShip(&yourDestroyer);
                break;
        }

    }



    while(true)
    {

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

void printOptions(Ship *aircraftCarrier, Ship *battleShip, Ship *submarine, Ship *cruiser, Ship *destroyer)
{

    cout << "1) " << aircraftCarrier->getName() << " (" << aircraftCarrier->getLength() << " spaces)"<< endl;
    cout << "2) " << battleShip->getName() << " (" << battleShip->getLength() << " spaces)"<<  endl;
    cout << "3) " << submarine->getName() << " (" << submarine->getLength() << " spaces)"<<  endl;
    cout << "4) " << cruiser->getName() << " (" << cruiser->getLength() << " spaces)"<<  endl;
    cout << "5) " << destroyer->getName() << " (" << destroyer->getLength() << " spaces)"<<  endl;
    cout << "Ship to place: ";

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

    cout << "Location of " << ship->getName() << " (" << ship->getLength() << " spaces): ";
    cin >> locationTemp;
    cout << "0 for up and down. 1 for left and right: ";
    cin >> rightLeftTemp;

    ship->setLocation(getInput(locationTemp)[0], getInput(locationTemp)[1], rightLeftTemp);

    for(Ship *tempShip : ships)
    {
        for(unsigned int i = 0; i < tempShip->getLocation()->size(); i++)
        {
            for(unsigned int j = 0; j < ship->getLocation()->size(); j++)
            {

                if(tempShip->getLocation()->at(i).at(0) == ship->getLocation()->at(j).at(0) && tempShip->getLocation()->at(i).at(1) == ship->getLocation()->at(j).at(1) && tempShip->getName().compare(ship->getName()) != 0)
                {
                    cout << "CANNOT OVERLAP SHIPS!" << endl;
                    ship->setInited(false);
                }
            }
        }
    }

    printShip(ship);

}

void printShip(Ship *ship)
{
    if(ship->getInited())
    {

        for(unsigned int i = 0; i < ship->getLocation()->size(); i++)
        {
            putValue(&yourBoard, ship->getLocation()->at(i).at(0), ship->getLocation()->at(i).at(1), '#');
        }
    }

}
