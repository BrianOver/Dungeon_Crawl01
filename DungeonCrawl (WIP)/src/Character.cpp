#include "Character.h"

Character::Character()
{
    Setname("Brian");
    Sethealth(10);
    Setgold(0);
    SetdexS(1);
    SetstrenthS(1);
    SetwisdomS(1);
    Setxpos(2);
    Setypos(2);
}

Character::Character(string str)
{
    Setname(str);
    Sethealth(10);
    Setgold(0);
    SetdexS(1);
    SetstrenthS(1);
    SetwisdomS(1);
    Setxpos(2);
    Setypos(2);
}

Character::Character(string str, int xpos, int ypos, int strength, int dex, int wisdom)
{
    Setname(str);
    Sethealth(10);
    Setgold(0);
    SetdexS(dex);
    SetstrenthS(strength);
    SetwisdomS(wisdom);
    Setxpos(xpos);
    Setypos(ypos);
}

Character::~Character()
{}

void Character::MovePlayer(int x, int y, bool m)
{
    if(m)
    {
        Setxpos(y);
        Setypos(x);
    }
    else
    {
        cout << "You cannot move there!";
    }
}

void Character::PrintStats()
{
    cout << "Name: " << Getname() << endl;
    cout << "Health: " << Gethealth() << endl;
    cout << "Gold: " << Getgold() << endl;
    cout << "Dexterity: " << GetdexS() << endl;
    cout << "Strength: " << GetstrenthS() << endl;
    cout << "Wisdom: " << GetwisdomS() << endl;
}
