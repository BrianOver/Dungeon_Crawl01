#ifndef DUNGEON_H
#define DUNGEON_H
#include "iostream"
#include<bits/stdc++.h>

using namespace std;

class Dungeon
{
    public:
        Dungeon(); //Build
        Dungeon(int x, int y);
        virtual ~Dungeon() { delete walls;}; //Delete

        void GenerateWalls(); //Make walls

        void toString(); //Print out dung
        void PrintToFile(); //Print out dung to file
        void PrintRoom(int** room); //Print out a Room/Custom 2-d array
        void PrintRoomToFile(int** room); // Print out a Room/Custom 2-d array to File

        int** GetWalls() {return walls;}; //Get walls
        void SetWalls(int** val) {walls = val;}; //Get walls

        int** GetRoom() {return room;}; //Get room
        void SetRoom(int** val) {room = val;}; //Get room

        void GenerateRooms(); //Unfinished

        void NewLevel(); //Unfinished

        int Getxlimit() {return xlimit;}; //Get xSize
        void Setxlimit(int val) {xlimit = val;}; //Set xSize

        int Getylimit() {return ylimit;}; //Get ySize
        void Setylimit(int val) {ylimit = val;}; //Set ySize

        bool inBounds(int x, int y); //Checking bounds
        bool inRoom(int x, int y); //Unfinished

        void SetPlayerLoc(int x1, int y1, int x2, int y2);

        void LoadRoom();
        void GenerateRoom();

    protected:

    private: //Var's
        int xlimit;
        int ylimit;
        int** walls;
        int** room;
};

#endif // DUNGEON_H
