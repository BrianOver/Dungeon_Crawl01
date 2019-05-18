#include "Dungeon.h"
#include "array"
#include "iostream"
#include "fstream"
#include "conio.h"

using namespace std;
Dungeon::Dungeon()
{
    Setxlimit(25);
    Setylimit(25);
    GenerateWalls();
    GenerateRooms();
}

Dungeon::Dungeon(int x, int y)
{
    Setxlimit(x);
    Setylimit(y);
    GenerateWalls();
    GenerateRooms();
}

void Dungeon::GenerateWalls()
{
    int** tempWalls = new int*[Getxlimit()]; //Creating the array
    for(int i = 0; i < Getxlimit(); i++)
    {
        tempWalls[i] = new int[Getylimit()];
    }

    for(int x = 0; x < Getxlimit(); x++) //Setting middle all 0 and walls to 1
    {
        for(int y = 0; y < Getylimit(); y++)
        {
            if(x != 0 && x != Getxlimit()-1 && y != 0 && y != Getylimit()-1)
            {
                tempWalls[x][y] = 0;
            }
            else
            {
                tempWalls[x][y] = 1;
            }
        }
    }

    tempWalls[2][2] = 3; //Setting default starting location
    SetWalls(tempWalls); //Setting walls to tempWalls
    //delete tempWalls;
}

void Dungeon::GenerateRooms()
{
    int** tempWalls = GetWalls();
    int randomNumOfRooms = rand() % (Getxlimit()*Getylimit());
    int limitRooms = 0;

    for(int y = 0; y < Getylimit(); y++)
    {
        for(int x = 0; x < Getxlimit(); x++)
        {
            if(limitRooms == randomNumOfRooms)
            {
                break;
            }
            else if(tempWalls[y][x] == 1)
            {
                continue;
            }
            else if(tempWalls[y][x] == 3)
            {
                continue;
            }
            else
            {
                int chanceNum = rand() % (Getxlimit());
                if(chanceNum == 2)
                {
                    tempWalls[y][x] = 2;
                    limitRooms++;
                }
                continue;
            }
        }
     }
    SetWalls(tempWalls);
}

void Dungeon::GenerateRoom()
{
    int** tempRoom = new int*[10]; //Creating the array
    for(int i = 0; i < 10; i++)
    {
        tempRoom[i] = new int[10];
    }

    for(int x = 0; x < 10; x++) //Setting middle all 0 and walls to 1
    {
        for(int y = 0; y < 10; y++)
        {
            if(x != 0 && x != 9 && y != 0 && y != 9)
            {
                tempRoom[x][y] = 0;
            }
            else
            {
                tempRoom[x][y] = 1;
            }
        }
    }

    tempRoom[5][0] = 2;
    tempRoom[1][1] = 3; //Setting default starting location
    SetRoom(tempRoom); //Setting Room to tempRoom
}

void Dungeon::LoadRoom()
{
    cout << "LOADROOM" << endl;

    GenerateRoom();
    PrintRoom(GetRoom());
    PrintRoomToFile(GetRoom());

    //string input = "";
    //cin >> input;
}

void Dungeon::SetPlayerLoc(int x1, int y1, int x2, int y2)
{
    int** tempWalls = GetWalls();
    if(tempWalls[y2][x2] == 2)
    {
        LoadRoom();
        tempWalls[y1][x1] = 0;
    }
    else
    {
        tempWalls[y2][x2] = 3;
        tempWalls[y1][x1] = 0;
    }
    SetWalls(tempWalls);
}

bool Dungeon::inBounds(int x, int y) //Checking if in bounds of dungeon
{
    int** tempWalls = GetWalls();
    if(tempWalls[y][x] != 1 && y != Getylimit() && x != Getxlimit() && y != 0 && x != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Dungeon::inRoom(int x, int y)
{
    int** tempWalls = GetWalls();
    if(tempWalls[y][x] == 2)
    {
        return true;
    }
    else
    {
         return false;
    }
}

void Dungeon::toString() //Prints out dungeon
{
    int** temp = GetWalls();

    for(int i = 0; i < Getxlimit(); i++)
    {
        for(int s = 0; s < Getylimit(); s++)
        {
            if(temp[i][s] == 2)
            {
                //system("COLOR 04");
            }
            else if(temp[i][s] == 3)
            {
                //system("COLOR 06");
            }
            else
            {
                //system("COLOR 0f");
            }
            cout << temp[i][s] << " ";
        }
        cout << endl;
    }
}

void Dungeon::PrintToFile() //Prints out dungeon to file
{
    fstream output;
    output.open("output.txt", ios::out | ios::trunc);
    output.close();

    output.open("output.txt", ios::out);
    int** temp = GetWalls();

    for(int i = 0; i < Getxlimit(); i++)
    {
        for(int s = 0; s < Getylimit(); s++)
        {
            output << temp[i][s];
        }
        output << endl;
    }
    output.close();
}

void Dungeon::PrintRoom(int ** r)
{
    int** room = r;
     for(int i = 0; i < 10; i++)
    {
        for(int s = 0; s < 10; s++)
        {
            if(room[i][s] == 2)
            {
                //system("COLOR 04");
            }
            else if(room[i][s] == 3)
            {
                //system("COLOR 06");
            }
            else
            {
                //system("COLOR 0f");
            }
            cout << room[i][s] << " ";
        }
        cout << endl;
    }
}

void Dungeon::PrintRoomToFile(int** r)
{
    fstream output;
    output.open("RoomOutput.txt", ios::out | ios::trunc);
    output.close();

    output.open("RoomOutput.txt", ios::out);
    int** temp = GetRoom();

    for(int i = 0; i < 10; i++)
    {
        for(int s = 0; s < 10; s++)
        {
            output << temp[i][s];
        }
        output << endl;
    }
    output.close();
}
