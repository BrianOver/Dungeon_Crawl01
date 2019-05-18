#include "MainGame.h"
#include "Character.h"
#include "Dungeon.h"
#include "windows.h"
#include "iostream"
#include "string"

using namespace std;

MainGame::MainGame()
{
    BuildGame();
}

MainGame::~MainGame()
{}

void MainGame::BuildGame()
{
    cout << "Welcome to the game!" << endl;
    cout << "I hope you enjoy" << endl;
    string input;
    while(true)
    {
        cout << "Ready to begin? (y/n)" << endl;
        cin >> input;
        if(input == "y" || input == "Y")
        {
            cout << "GREAT!";
            clear();
            break;
        }
        else if(input == "n" || input == "N")
        {
            cout << "Fuck you" << endl << endl << endl;
            exit(0);
        }
        else
        {
            continue;
        }
    }

    string name;
    while(true)
    {
        cout << "What is your name adventurer?" << endl;
        cin >> name;
        break;
    }

    int dungSize = 0;
    while(true)
    {
        cout << "Whats the size of your Dungeon? (Enter one number)" << endl;
        cin >> input;
        if(isInteger(input))
        {
            dungSize = stoi(input);
            break;
        }
        else
        {
            cout << "Why don't you try again?" << endl;
            continue;
        }
    }

    SetdungSize(dungSize);
    cout << "Wonderful! You are not completely incompetent" << endl;
    clear();

    Dungeon* dung = new Dungeon(dungSize,dungSize);
    Character* player = new Character(name);
    SetDungeon(dung);
    SetCharacter(player);

    dung -> toString();
    dung -> PrintToFile();
}

void MainGame::RunGame()
{
    Dungeon* dung = GetDungeon();
    Character* player = GetCharacter();
    while(true)
    {
        string inputs;
        cout << "What do you want to do? (move/stats/i)" << endl;
        cin >> inputs;
        if(inputs == "move" || inputs == "Move")
        {
            Move();
            continue;
        }
        else if(inputs == "stats" || inputs == "Stats")
        {
            Stats();
            continue;
        }
        else if(inputs == "TestRoom")
        {
            MoveToNearestRoom();
        }
        else
        {
            clear();
            dung -> toString();
            dung -> PrintToFile();
            continue;
        }
    }
}

void MainGame::MoveToNearestRoom()
{
    clear();
    cout << "TESTING ROOM" << endl;

    Dungeon* dung = GetDungeon();
    Character* player = GetCharacter();

    int** walls = dung -> GetWalls();

    for(int y = 0; y < dungSize; y++)
    {
        for(int x = 0 ; x < dungSize; x++)
        {
            if(walls[y][x] == 2)
            {
                int oldx = player -> Getxpos();
                int oldy = player -> Getypos();
                player -> MovePlayer(x ,y , true);
                dung -> SetPlayerLoc(oldx, oldy, x , y);
                //clear();
                //dung -> toString();
            }
        }
    }
}

void MainGame::Move()
{
    Dungeon* dung = GetDungeon();
    Character* player = GetCharacter();

    clear();
    dung -> toString();
    dung -> PrintToFile();

    string inputx;
    string inputy;
    while(true)
    {
        while(true)
        {
            cout << "Move to what x? ";
            cin >> inputx;
            if(isInteger(inputx))
            {
                break;
            }
            else
            {
                cout << "Try again" << endl;
                continue;
            }
        }
        while(true)
        {
            cout << "Move to what y? ";
            cin >> inputy;
            if(isInteger(inputy))
            {
                break;
            }
            else
            {
                cout << "Try again" << endl;
                continue;
            }
        }

        clear();
        int xmove = stoi(inputx);
        int ymove = stoi(inputy);
        cout << endl << xmove << " " << ymove << endl;
        if(dung -> inBounds(xmove,ymove))
        {
            int oldx = player -> Getxpos();
            int oldy = player -> Getypos();
            player -> MovePlayer(xmove,ymove, true);
            dung -> SetPlayerLoc(oldx, oldy, xmove, ymove);
            cout << endl;
            player -> PrintPos();
            cout << endl;
        }
        else
        {
            cout << "Wow you are dense";
            clear();
            continue;
        }
        clear();
        dung -> toString();
        dung -> PrintToFile();
        break;
    }
}

void MainGame::Inventory()
{

}

void MainGame::Stats()
{
    clear();
    Character* player = GetCharacter();
    player -> PrintStats();
}

void MainGame::clear()
{
    COORD topLeft  = { 0, 0 };
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
        console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
        console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
        screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

inline bool MainGame::isInteger(const std::string & s)
{
    if(s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false ;

    char * p ;
    strtol(s.c_str(), &p, 10) ;

    return (*p == 0) ;
}
