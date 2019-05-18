#ifndef MAINGAME_H
#define MAINGAME_H

#include "Dungeon.h"
#include "Character.h"
#include "iostream"
#include "string"
#include "array"

using namespace std;

class MainGame
{
    public:
        MainGame();
        virtual ~MainGame();

        void SetDungeon(Dungeon* d) {dung = d;};
        Dungeon* GetDungeon() {return dung;};

        void SetCharacter(Character* c) {player = c;};
        Character* GetCharacter() {return player;};

        void SetdungSize(int val) {dungSize = val;};
        int GetdungSize() {return dungSize;};

        void BuildGame();
        void RunGame();

        void clear();

        inline bool isInteger(const std::string & s);

        void Move();
        void Stats();
        void Inventory();
        void Combat();
        void Loot();

        //Debugging
        void MoveToNearestRoom();

    protected:

    private:
        Dungeon* dung;
        Character* player;
        int dungSize;
};

#endif // MAINGAME_H
