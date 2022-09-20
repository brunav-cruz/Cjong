#include <stdio.h>
#include <conio.h>
#include <wchar.h>
#include <windows.h>
#include <stdlib.h>


void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Reset(){
    system("cls");
}

void quit(){
    Reset();
    exit(1);
}