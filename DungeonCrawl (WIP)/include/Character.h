#ifndef CHARACTER_H
#define CHARACTER_H

#include "string"
#include "iostream"

using namespace std;

class Character
{
    public:
        Character();
        Character(string name);
        Character(string name, int x, int y, int s, int d, int w);
        virtual ~Character();

        string Getname() { return name; }
        void Setname(string val) { name = val; }
        int GetstrenthS() { return strenthS; }
        void SetstrenthS(int val) { strenthS = val; }
        int GetdexS() { return dexS; }
        void SetdexS(int val) { dexS = val; }
        int GetwisdomS() { return wisdomS; }
        void SetwisdomS(int val) { wisdomS = val; }
        int Getgold() { return gold; }
        void Setgold(int val) { gold = val; }
        int Getxpos() { return xpos; }
        void Setxpos(int val) { xpos = val; }
        int Getypos() { return ypos; }
        void Setypos(int val) { ypos = val; }
        int Gethealth() { return health; }
        void Sethealth(int val) { health = val; }

        void PrintPos() {cout << Getxpos() << " " << Getypos();};

        void MovePlayer(int x, int y, bool m);

        void PlayerInventory();
        void PrintStats();

    protected:

    private:
        string name;
        int strenthS;
        int dexS;
        int wisdomS;
        int gold;
        int xpos;
        int ypos;
        int health;
};

#endif // CHARACTER_H
