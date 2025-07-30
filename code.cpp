// This is code for the snake game using c++ language 
#include <iostream>
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

}

void input(){

}

void logic(){

}


int main(){
    setup();
    return 0;
}