// This is code for the snake game using c++ language 
#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

bool GameOver;
const int height = 20;
const int width = 20;
int x,y,fruitX,fruitY,score;

/* 
enum in C++ is a user-defined data type that assigns names to a set of constant integer values,
making the code more readable and organized
*/
enum Direction {STOP = 0, LEFT, RIGHT, UP, DOWN};
Direction dir;

void setup(){
    GameOver = false;
    dir = STOP;
    x = width/2;
    y = height/2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
}

void draw(){
    system("cls");
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if(i==0 || i==height-1 || j==0 || j==width-1){
                cout << "#";
            }else if(i==y && j==x){
                cout << "o";
            }else if(i==fruitY && j==fruitX){
                cout << "F";
            }else{
                cout << " ";
            }
        }
        cout << endl;
    }
}

/*
_kbhit() and _getch() from <conio.h>:
kbhit() is an old function from Turbo C++ (not supported in modern GCC ❌)
_kbhit() is the Microsoft-specific version (with underscore)
Works in Windows using MinGW or MSVC
_kbhit() → Checks if a key is pressed (non-blocking)
_getch() → Reads the key without needing to press Enter
Useful for real-time input in games like Snake
*/

void input(){
    if(_kbhit()){
        switch (_getch()){
        case 'a': dir = LEFT;
            break;
        case 'd': dir = RIGHT;
            break;
        case 'w': dir = UP;
            break;                
        case 's': dir = DOWN;
            break;
        case 'x' : GameOver=true;
            break;
        }
    }
}

void logic(){
    switch(dir){
        case LEFT:
        x--;
        break;

        case RIGHT:
        x++;
        break;
        
        case UP:
        y--;
        break;
        
        case DOWN:
        y++;
        break;
    }
    if(x <= 0 || x >= width || y <= 0 || y >= height)
        GameOver = true;
}


int main(){
    setup();
    while(!GameOver){
        draw();
        input();
        logic();
        Sleep(300);
    }
    return 0;
}