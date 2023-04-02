#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>
using namespace std;

int enemyX = 4;
int enemyY = 10;

int tomX = 6;
int tomY = 18;

int TurX = 101;
int TurY = 6;

int bulletX[100];
int bulletY[100];
int bulletCount = 0;

int score = 0;
int lives = 3;

string enemyDirection = "Right";
string turtleDirection = "Left";
int timer = 0;
int turTimer = 0;

int fruitsX[5] = {10, 50, 65, 35, 100};
int fruitsY[5] = {5, 20, 15, 18, 1};

char tom1[15] = {' ', ' ', '_', ' ', ' ', ' ', ',', '_', ',', ' ', ' ', ' ', '_', ' ', ' '};
char tom2[15] = {' ', '/', ' ', '`', '\'', '=', ')', ' ', '(', '=', '\'', '`', ' ', '\\', ' '};
char tom3[15] = {'/', '.', '-', '.', '-', '.', '\\', ' ', '/', '.', '-', '.', '-', '.', '\\'};
char tom4[15] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', '\'', ' ', ' ', ' ', ' ', ' ', ' ', ' '};

char cheetah1[16] = {',', '-', '-', '-', '-', '-', ',', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
char cheetah2[16] = {',', '-', '-', '\'', '-', '-', '-', ':', '-', '-', '-', '`', '-', '-', ','};
char cheetah3[16] = {'=', '=', '(', 'o', ')', '-', '-', '-', '-', '-', '(', 'o', ')', '=', '=', 'J'};

char turtle1[13] = {' ', ' ', '_', '_', '_', '_', '_', '_', ' ', ' ', ' ', ' ', ' '};
char turtle2[13] = {' ', '/', '|', '_', '|', '|', '_', '\\', '`', '.', '_', ' ', ' '};
char turtle3[13] = {'(', ' ', ' ', '_', ' ', '_', ' ', ' ', '_', ' ', '_', '\\', ' '};
char turtle4[13] = {'=', '`', '-', '(', '_', ')', '-', '-', '(', '_', ')', '-', '\''};

// Functions declaration
void header();
int menu();
int option();
int keys();
int instruction();
void road();
void moveBullet();
void generateBullet();
void removeBulletFromArray(int index);
void gotoxy(int x, int y);
void moveCheetah();
void printCheetah();
void eraseCheetah();
void moveTurtle();
void printTurtle();
void eraseTurtle();
void printTom();
char getCharAtxy(short int x, short int y);

void generateFruits();
void removeFruits();
void printFruits();
void printScore();

void bulletCollision();
void printBullet(int x, int y);
void eraseBullet(int x, int y);

void moveTomUp();
void moveTomDown();
void moveTomLeft();
void moveTomRight();
void eraseTom();

main()
{

    system("cls");
    header();

    int menuFun = menu();

    if (menuFun == 2)
    {
        while (true)
        {
            int optionFun = option();

            if (optionFun == 1)
            {
                int keyFun = keys();
                if (keyFun == 0)
                {
                    int optionFun = option();
                }
            }
            else if (optionFun == 2)
            {
                int instructionFun = instruction();
                if (instructionFun == 0)
                {
                    int optionFun = option();
                }
            }
            else if (optionFun == 3)
            {
                system("cls");
                int menuFun = menu();
            }
        }
    }

    if (menuFun == 3)
    {
        cout << "You have successfully exit the game";
    }

    if (menuFun == 1)
    {
        system("cls");
        road();
        generateFruits();
        printFruits();
        printCheetah();
        printTurtle();
        printTom();

        while (true)
        {
            if (GetAsyncKeyState(VK_LEFT))
            {
                moveTomLeft();
            }
            if (GetAsyncKeyState(VK_RIGHT))
            {
                moveTomRight();
            }
            if (GetAsyncKeyState(VK_UP))
            {
                moveTomUp();
            }
            if (GetAsyncKeyState(VK_DOWN))
            {
                moveTomDown();
            }
            if (GetAsyncKeyState(VK_SPACE))
            {
                generateBullet();
            }
            printFruits();
            moveBullet();
            printScore();
            if (timer == 1)
            {
                moveCheetah();
                timer = 0;
            }
            if (turTimer == 3)
            {
                moveTurtle();
                turTimer = 0;
            }
            timer++;
            turTimer++;
            Sleep(30);
            if (lives<=0)
            {
                break;
            }
        }
        system("cls");
        cout << "Your Total Score is " << score << endl;
    }
}
void header()
{
    cout << " _______                    _________                                    ________     " << endl;
    cout << "|            |        |    |          \\    |         |        _-_       |        \\    " << endl;
    cout << "|            |  \\     |    |           |   |         |      /     \\     |         |   " << endl;
    cout << "|_______     |   \\    |    |           |   |         |     |       |    |________/    " << endl;
    cout << "|            |    \\   |    |           |   |    /\\   |     |  ---  |    |\\           " << endl;
    cout << "|            |     \\  |    |           |   |   /  \\  |     |       |    |  \\         " << endl;
    cout << "|            |      \\ |    |          |    |  /    \\ |     |       |    |    \\       " << endl;
    cout << "|_______     |        |    |_________/     |         |     |       |    |      \\     " << endl;
    cout << endl;
    cout << endl;
    cout << endl;
}
int menu()
{
    int option;
    cout << "Menu." << endl;
    cout << endl;
    cout << "___________________" << endl;
    cout << "1. Start" << endl;
    cout << "2. Option" << endl;
    cout << "3. Exit" << endl;
    cout << endl;
    cout << "Enter one option:  ";
    cin >> option;
    return option;
}
int option()
{
    system("cls");
    int option;
    cout << "1. Keys" << endl;
    cout << "2. Instruction" << endl;
    cout << "3. Exit" << endl;
    cout << endl;
    cout << "Enter one option:  ";
    cin >> option;
    return option;
}
int keys()
{
    int option;
    system("cls");
    cout << "Keys" << endl;
    cout << endl;
    cout << "___________________" << endl;
    cout << "1. UP              Go up" << endl;
    cout << "2. Down            Go down" << endl;
    cout << "1. Left            Go left" << endl;
    cout << "1. Right           Go right" << endl;
    cout << "1. Space           For fire" << endl;
    cout << "1. ESC             To end game" << endl;
    cout << "Press 0 to go back to submenu:  ";
    cin >> option;
}
int instruction()
{
    int option;
    system("cls");
    cout << "Instructions" << endl;
    cout << endl;
    cout << "___________________" << endl;
    cout << "1. Do not collide with enemies." << endl;
    cout << "2. Pick treasure with the help of fire." << endl;
    cout << endl;
    cout << "Press 0 to go back to submenu:  ";
    cin >> option;
    return option;
}
void road()
{
    cout << " _________________________________________________________________________________________________________________" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << "|                                                                                                                 |" << endl;
    cout << " _________________________________________________________________________________________________________________ " << endl;
}

void printCheetah()
{
    gotoxy(enemyX, enemyY);
    for (int index = 0; index < 16; index++)
    {
        cout << cheetah1[index];
    }
    gotoxy(enemyX, enemyY + 1);
    for (int index = 0; index < 16; index++)
    {
        cout << cheetah2[index];
    }
    gotoxy(enemyX, enemyY + 2);
    for (int index = 0; index < 16; index++)
    {
        cout << cheetah3[index];
    }
}
void printTurtle()
{
    gotoxy(TurX, TurY);
    for (int index = 0; index < 13; index++)
    {
        cout << turtle1[index];
    }
    gotoxy(TurX, TurY + 1);
    for (int index = 0; index < 13; index++)
    {
        cout << turtle2[index];
    }
    gotoxy(TurX, TurY + 2);
    for (int index = 0; index < 13; index++)
    {
        cout << turtle3[index];
    }
    gotoxy(TurX, TurY + 3);
    for (int index = 0; index < 13; index++)
    {
        cout << turtle4[index];
    }
}
void printTom()
{
    gotoxy(tomX, tomY);
    for (int index = 0; index < 15; index++)
    {
        cout << tom1[index];
    }
    gotoxy(tomX, tomY + 1);
    for (int index = 0; index < 15; index++)
    {
        cout << tom2[index];
    }
    gotoxy(tomX, tomY + 2);
    for (int index = 0; index < 15; index++)
    {
        cout << tom3[index];
    }
    gotoxy(tomX, tomY + 2);
    for (int index = 0; index < 15; index++)
    {
        cout << tom4[index];
    }
}
void eraseCheetah()
{
    gotoxy(enemyX, enemyY);
    for (int index = 0; index < 16; index++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 1);
    for (int index = 0; index < 16; index++)
    {
        cout << " ";
    }
    gotoxy(enemyX, enemyY + 2);
    for (int index = 0; index < 16; index++)
    {
        cout << " ";
    }
}
void eraseTurtle()
{
    gotoxy(TurX, TurY);
    for (int index = 0; index < 13; index++)
    {
        cout << " ";
    }
    gotoxy(TurX, TurY + 1);
    for (int index = 0; index < 13; index++)
    {
        cout << " ";
    }
    gotoxy(TurX, TurY + 2);
    for (int index = 0; index < 13; index++)
    {
        cout << " ";
    }
    gotoxy(TurX, TurY + 3);
    for (int index = 0; index < 13; index++)
    {
        cout << " ";
    }
}
void moveCheetah()
{

    if (enemyDirection == "Left")
    {
        char next = getCharAtxy(enemyX - 1, enemyY);
        if (next == ' ' || next == '@')
        {
            eraseCheetah();
            enemyX--;
            printCheetah();
        }
        if (next == '|')
        {
            enemyDirection = "Right";
        }
    }
    if (enemyDirection == "Right")
    {
        char next = getCharAtxy(enemyX + 16, enemyY);
        if (next == ' ' || next == '@')
        {
            eraseCheetah();
            enemyX++;
            printCheetah();
        }
        if (next == '|')
        {
            enemyDirection = "Left";
        }
    }
}
void moveTurtle()
{

    if (turtleDirection == "Left")
    {
        char next = getCharAtxy(TurX - 1, TurY);
        if (next == ' ' || next == '@')
        {
            eraseTurtle();
            TurX--;
            printTurtle();
        }
        if (next == '|')
        {
            turtleDirection = "Right";
        }
    }
    if (turtleDirection == "Right")
    {
        char next = getCharAtxy(TurX + 15, TurY);
        if (next == ' ' || next == '@')
        {
            eraseTurtle();
            TurX++;
            printTurtle();
        }
        if (next == '|')
        {
            turtleDirection = "Left";
        }
    }
}
void moveTomLeft()
{
    char next = getCharAtxy(tomX - 1, tomY);
    if (next == ' ')
    {
        eraseTom();
        tomX = tomX - 1;
        printTom();
    }
    else{
        eraseTom();
        printTom();
        if (next != '|')
        {
            eraseTom();
            lives--;
            tomY = 18;
        }

    }
}

void moveTomRight()
{
    char next = getCharAtxy(tomX + 17, tomY);
    if (next == ' ')
    {
        eraseTom();
        tomX = tomX + 1;
        printTom();
    }
    else{
        eraseTom();
        printTom();
        if (next != '|')
        {
            eraseTom();
            lives--;
            tomY = 18;
        }
    }
    
}

void moveTomUp()
{
    char next = getCharAtxy(tomX, tomY - 1);
    if (next == ' ')
    {
        eraseTom();
        tomY = tomY - 1;
        printTom();
    }
    else{
        eraseTom();
        printTom();
        if (next != '_')
        {
            eraseTom();
            lives--;
            tomY = 18;
        }
    }
    
}

void moveTomDown()
{
    char next = getCharAtxy(tomX+9, tomY + 4);
    if (next == ' ')
    {
        eraseTom();
        tomY = tomY + 1;
        printTom();
    }
    else{
        eraseTom();
        printTom();
        if (next != '_')
        {
            eraseTom();
            lives--;
            tomY = 18;
        }
    }
}
void eraseTom()
{
    gotoxy(tomX, tomY);
    for (int index = 0; index < 15; index++)
    {
        cout << " ";
    }
    gotoxy(tomX, tomY + 1);
    for (int index = 0; index < 15; index++)
    {
        cout << " ";
    }
    gotoxy(tomX, tomY + 2);
    for (int index = 0; index < 15; index++)
    {
        cout << " ";
    }
    gotoxy(tomX, tomY + 3);
    for (int index = 0; index < 15; index++)
    {
        cout << " ";
    }
}
void generateBullet()
{
    bulletX[bulletCount] = tomX + 7;
    bulletY[bulletCount] = tomY;
    gotoxy(tomX + 7, tomY);
    cout << ".";
    bulletCount++;
}

void moveBullet()
{
    for (int x = 0; x < bulletCount; x++)
    {
        char next = getCharAtxy(bulletX[x], bulletY[x] - 1);
        if (next != ' ')
        {
            eraseBullet(bulletX[x], bulletY[x]);
            removeBulletFromArray(x);
            if (next == '@')
            {
                score++;
                removeFruits();
                generateFruits();
                if (score%10 == 0)
                {   
                    srand(time(0));
                    eraseCheetah();
                    eraseTurtle();
                    enemyY = 5 + rand()%10;
                    TurY = enemyY - (4 + rand()%5);
                }
            }
        }
        else
        {
            eraseBullet(bulletX[x], bulletY[x]);
            bulletY[x] = bulletY[x] - 1;
            printBullet(bulletX[x], bulletY[x]);
        }
    }
}

void removeBulletFromArray(int index)
{
    for (int x = index; x < bulletCount - 1; x++)
    {
        bulletX[x] = bulletX[x + 1];
        bulletY[x] = bulletY[x + 1];
    }
    bulletCount--;
}

void printBullet(int x, int y)
{
    gotoxy(x, y);
    cout << "`";
}
void eraseBullet(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}

void generateFruits(){
    srand(time(0));
    for (int i=0; i<5; i++){
        fruitsX[i] = rand() % 100;
        fruitsY[i] = rand() % 15;
    }
}

void printFruits(){
    for (int i=0; i<5; i++){
        gotoxy(fruitsX[i]+5,fruitsY[i]+1);
        cout << "@";
    }
}

void removeFruits()
{
    for (int i=0; i<5; i++){
        gotoxy(fruitsX[i]+5,fruitsY[i]+1);
        cout << " ";
    } 
}

void printScore(){
    gotoxy(1,25);
    cout << " Score: "<< score << "\t Lives: "<< lives <<endl;
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}