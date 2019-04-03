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
#include <limits>
#include <cstdlib>
#include <ctime>

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

Ship theirAircraftCarrier("Aircraft Carrier", 5);
Ship theirBattleShip("Battle Ship", 4);
Ship theirSubmarine("Submarine", 3);
Ship theirCruiser("Cruiser", 3);
Ship theirDestroyer("Destroyer", 2);

vector<Ship*> yourShips{&yourAircraftCarrier, &yourBattleShip, &yourSubmarine, &yourCruiser, &yourDestroyer};
vector<Ship*> theirShips{&theirAircraftCarrier, &theirBattleShip, &theirSubmarine, &theirCruiser, &theirDestroyer};

int main()
{



    cout << "Select where to place your ships" << endl;

    while(!yourAircraftCarrier.getInited() ||
          !yourBattleShip.getInited() ||
          !yourSubmarine.getInited() ||
          !yourCruiser.getInited() ||
          !yourDestroyer.getInited())
    {

        printBoard(&yourBoard);

        unsigned int input;
        printOptions(&yourShips);

        cin >> input;

        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }

        if(input > 0 && input <= yourShips.size())
        {
            switch(input)
            {
                case 1:
                    placeShip(&yourShips, 0);
                    break;
                case 2:
                    placeShip(&yourShips, 1);
                    break;
                case 3:
                    placeShip(&yourShips, 2);
                    break;
                case 4:
                    placeShip(&yourShips, 3);
                    break;
                case 5:
                    placeShip(&yourShips, 4);
                    break;
            }

        }
        else
        {
            cout << endl << "NOT A VALID SHIP" << endl;
        }



    }

    while(!theirAircraftCarrier.getInited() ||
          !theirBattleShip.getInited() ||
          !theirSubmarine.getInited() ||
          !theirCruiser.getInited() ||
          !theirDestroyer.getInited())
    {

        string tempLocation;
        int tempDirection;
        srand(time(NULL));
        int rand();

        if(!theirAircraftCarrier.getInited())
        {
            tempLocation.clear();
            tempLocation += static_cast<char>((rand() % 10) + 'A');
            tempLocation += to_string((rand() % 10) + 1);

            tempDirection = (rand() % 2);

            placeShipComp(&theirShips, 0, tempLocation, tempDirection);
        }

        if(!theirBattleShip.getInited())
        {
            tempLocation.clear();
            tempLocation += static_cast<char>((rand() % 10) + 'A');
            tempLocation += to_string((rand() % 10) + 1);

            tempDirection = (rand() % 2);

            placeShipComp(&theirShips, 1, tempLocation, tempDirection);
        }

        if(!theirSubmarine.getInited())
        {
            tempLocation.clear();
            tempLocation += static_cast<char>((rand() % 10) + 'A');
            tempLocation += to_string((rand() % 10) + 1);

            tempDirection = (rand() % 2);

            placeShipComp(&theirShips, 2, tempLocation, tempDirection);
        }

        if(!theirCruiser.getInited())
        {
            tempLocation.clear();
            tempLocation += static_cast<char>((rand() % 10) + 'A');
            tempLocation += to_string((rand() % 10) + 1);

            tempDirection = (rand() % 2);

            placeShipComp(&theirShips, 3, tempLocation, tempDirection);
        }

        if(!theirDestroyer.getInited())
        {
            tempLocation.clear();
            tempLocation += static_cast<char>((rand() % 10) + 'A');
            tempLocation += to_string((rand() % 10) + 1);

            tempDirection = (rand() % 2);

            placeShipComp(&theirShips, 4, tempLocation, tempDirection);
        }

   }


    while(!gameOver(&yourShips, & theirShips))
    {

        printBoard(&theirBoard);
        printBoard(&yourBoard);

        string input;
        cout << "Enter location: ";
        cin >> input;
        cout << endl;
        cout << "You fired at " + input + ": ";
        fire(&theirBoard, &theirShips, getInput(input)[0], getInput(input)[1]);
        compFire(&yourBoard);

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

void printOptions(vector<Ship*> *ships)
{

    for(unsigned int i = 0; i < ships->size(); i++)
    {
        cout << (ships->at(i)->getInited() ? "X" : "O") << " " << (i + 1) << ") " << ships->at(i)->getName() << " (" << ships->at(i)->getLength() << " spaces)"<< endl;
    }

    cout << "Ship to place: ";

}

void fire(vector<vector<char>> *board, vector<Ship*> *ships, int row, int column)
{

    bool hit = false;

    if(validInput(row, column))
    {
        for(unsigned int i = 0; i < ships->size(); i++)
        {
            for(unsigned int j = 0; j < ships->at(i)->getLocation()->size(); j++)
            {
                if(row == ships->at(i)->getLocation()->at(j).at(0) && column == ships->at(i)->getLocation()->at(j).at(1))
                {
                    ships->at(i)->setHits(row, column, true, j);
                    cout << "HIT" << endl;
                    putValue(board, row, column, 'X');
                    hit = true;
                    if(ships->at(i)->isSunk())
                    {
                        cout << "Sunk " + ships->at(i)->getName() << endl;
                    }
                }
            }
        }
    }
    else
    {
        cout << "INVALID CHOICE" << endl;
    }

    if(!hit)
    {
        putValue(board, row, column, '*');
        cout << "MISS" << endl;
    }

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

void placeShip(vector<Ship*> *ships, int index)
{
    string locationTemp;
    bool rightLeftTemp;

    cout << "Location of " << ships->at(index)->getName() << " (" << ships->at(index)->getLength() << " spaces): ";
    cin >> locationTemp;
    cout << "0 for up and down. 1 for left and right: ";
    cin >> rightLeftTemp;
    cout << endl;

    ships->at(index)->setLocation(getInput(locationTemp)[0], getInput(locationTemp)[1], rightLeftTemp);

    for(Ship *tempShip : *ships)
    {
        for(unsigned int i = 0; i < tempShip->getLocation()->size(); i++)
        {
            for(unsigned int j = 0; j < ships->at(index)->getLocation()->size(); j++)
            {

                if(tempShip->getLocation()->at(i).at(0) == ships->at(index)->getLocation()->at(j).at(0) && tempShip->getLocation()->at(i).at(1) == ships->at(index)->getLocation()->at(j).at(1) && tempShip->getName().compare(ships->at(index)->getName()) != 0)
                {
                    cout << "CANNOT OVERLAP SHIPS!" << endl;
                    ships->at(index)->setInited(false);
                }

                if(tempShip->getLocation()->at(i).at(0) < 0  || tempShip->getLocation()->at(i).at(1) < 0 || tempShip->getLocation()->at(i).at(0) >= rows || tempShip->getLocation()->at(i).at(1) >= columns)
                {
                    cout << "SHIP CANNOT GO OUT OF BOUNDS" << endl;
                    ships->at(index)->setInited(false);
                }

            }
        }
    }

    printShips(&yourBoard, ships);

}

void placeShipComp(vector<Ship*> *ships, int index, string location, bool rightLeft)
{

    ships->at(index)->setLocation(getInput(location)[0], getInput(location)[1], rightLeft);

    for(Ship *tempShip : *ships)
    {
        for(unsigned int i = 0; i < tempShip->getLocation()->size(); i++)
        {
            for(unsigned int j = 0; j < ships->at(index)->getLocation()->size(); j++)
            {

                if(tempShip->getLocation()->at(i).at(0) == ships->at(index)->getLocation()->at(j).at(0) && tempShip->getLocation()->at(i).at(1) == ships->at(index)->getLocation()->at(j).at(1) && tempShip->getName().compare(ships->at(index)->getName()) != 0)
                {
                    ships->at(index)->setInited(false);
                }

                if(tempShip->getLocation()->at(i).at(0) < 0  || tempShip->getLocation()->at(i).at(1) < 0 || tempShip->getLocation()->at(i).at(0) >= rows || tempShip->getLocation()->at(i).at(1) >= columns)
                {
                    ships->at(index)->setInited(false);
                }

            }
        }
    }

}

void printShips(vector<vector<char>> *board, vector<Ship*> *ships)
{

    for(unsigned int ship = 0; ship < ships->size(); ship++)
    {
        if(ships->at(ship)->getInited())
        {
            for(unsigned int i = 0; i < ships->at(ship)->getLocation()->size(); i++)
            {
                putValue(board, ships->at(ship)->getLocation()->at(i).at(0), ships->at(ship)->getLocation()->at(i).at(1), '#');
            }
        }
    }
}

bool gameOver(vector<Ship*> *yourShips, vector<Ship*> *theirShips)
{

    bool youLose = true;
    bool theyLose = true;

    for(unsigned int i = 0; i < yourShips->size(); i++)
    {
        if(!yourShips->at(i)->isSunk())
        {
            youLose = false;
        }
    }

    for(unsigned int i = 0; i < theirShips->size(); i++)
    {
        if(!theirShips->at(i)->isSunk())
        {
            theyLose = false;
        }
    }

    if(youLose)
    {
        cout << "You lose" << endl;
        return true;
    }
    else if(theyLose)
    {
        cout << "You win!" << endl;
        return true;
    }
    else
    {
        return false;
    }

}

void compFire(vector<vector<char>> *board)
{

    string tempLocation = "";
    int tempDirection = -1;
    srand(time(NULL));
    int rand();


    while(tempLocation.compare("") == 0 || tempDirection == -1)
    {
        tempLocation += static_cast<char>((rand() % 10) + 'A');
        tempLocation += to_string((rand() % 10) + 1);
        tempDirection = (rand() % 2);

        if(board->at(getInput(tempLocation)[0]).at(getInput(tempLocation)[1]) == '#' ||
           board->at(getInput(tempLocation)[0]).at(getInput(tempLocation)[1]) == 'O')
        {
            cout << "They fired at " + tempLocation + ": ";
            fire(&yourBoard, &yourShips, getInput(tempLocation)[0], getInput(tempLocation)[1]);
        }
        else
        {
            tempLocation = "";
            tempDirection = -1;
        }

    }

}
