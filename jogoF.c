#include <stdio.h>
#include <wchar.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "console.h"
#include "menu.h"

void randomize();
void printpeca(int x,int y, char tipo);
void printtab();
void removePecas(int positionY, int positionX, int currentY, int currentX);
bool checkLivre(int i, int j);
void Select();

void main(){
    _setmode(_fileno(stdout), 0x00020000);
    Reset();
    randomize();
    printpeca(0, 0, '+');
    printtab();
    Select();
}


int pecas[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1, 1, 1, 1}};

char tipo;

void randomize(){
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    time_t t;
    srand((unsigned)time(&t));
    int time;

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 8; j++){
            if (pecas[i][j]!=0){
                tipo = '+';
                while (tipo == '+'){
                    pecas[i][j] = rand() % 4; 
                    if (pecas[i][j] == 0 && a < 12){
                        a += 1;
                        tipo = '%';
                    }
                    else if (pecas[i][j] == 1 && b < 12){
                        b += 1;
                        tipo = '$';
                    }
                    else if (pecas[i][j] == 2 && c < 12){
                        c += 1;
                        tipo = '#';
                    }
                    else if (pecas[i][j] == 3 && d < 12){
                        d += 1;
                        tipo = '@';
                    }
                }
                pecas[i][j] = tipo;
            }
        }
    }
}

void printpeca(int y, int x, char tipo)
{
    gotoxy((x * 5) + 62, (y * 5) + 10);
    wprintf(L"┌───┐");
    gotoxy((x * 5) + 62, (y * 5) + 11);
    wprintf(L"│   │");
    gotoxy((x * 5) + 62, (y * 5) + 12);
    wprintf(L"│ %ls  │", tipo);
    gotoxy((x * 5) + 62, (y * 5) + 13);
    wprintf(L"│   │");
    gotoxy((x * 5) + 62, (y * 5) + 14);
    wprintf(L"└───┘");
}

void printtab()
{
    for (int i = 0; i < 6; i++){
        for (int j = 0; i < 8; i++){
            if (pecas[i][j] != 0){
                tipo = pecas[i][j];
                printpeca(i, j, tipo);
            }
        }
    }
}

/* int checkVitoria(){
    for (int i = 0; i < 6; i++){
        for (int j = 0; i < 8; i++){

            if (pecas[i][j] != 0){
                return 0;
            }
        }

        return 1;
    }
}  */

void removePecas(int positionY, int positionX, int currentY, int currentX){
    
    pecas[positionY][positionX] == 0;
    pecas[currentY][currentX] == 0;
    Reset();
    printtab();
}

bool checkLivre(int i, int j){
    if (j == 0 || j == 7)
    {
        return true;
    }
    else if (pecas[i][j - 1] == 0)
    {
        return true;
    }
    else if (pecas[i][j + 1] == 0)
    {
        return true;
    }
    else
    {
        wprintf(L"%ls", pecas[i][j - 1]);
        return false;
    }
}

int score = 0;

void Select(){

    int x = 0;
    int y = 0;
    int selectedI = 0;
    int selectedJ = 0;
    int selecionou = 0;
    int i = 0;
    int j = 0;
    int keySelect = 0;

    while (1)
    {
        y = 64 + (j * 5);
        x = 11 + (i * 5);
        gotoxy(y, x);
        wprintf(L"*");

        if (_kbhit())
        {
            keySelect = _getch();

            if (keySelect == 0 || keySelect == 0xE0)
            {
                keySelect = _getch();
            }
            if (keySelect == 77 && j < 7)
            {
                j += 1;
            }
            else if (keySelect == 75 && j > 0)
            {
                j -= 1;
            }
            else if (keySelect == 80 && i > 0)
            {
                i -= 1;
            }
            else if (keySelect == 75 && i < 5)
            {
                i += 1;
            }
            
            else if (keySelect == 13 && selecionou == 0)
            {
                selectedI = i;
                selectedJ = j;
                selecionou = 1;
                gotoxy(y + 1, x);
                wprintf(L"o");
            }

            else if (keySelect == 13 && selecionou == 1)
            {
                if ((pecas[selectedI][selectedJ] == pecas[i][j]) && ((selectedI != i) && (selectedJ != j)))
                {
                    if (checkLivre(selectedI, selectedJ) && checkLivre(i, j))
                    {
                        removePecas(selectedI, selectedJ, i, j);
                        score += 10;
                        selecionou = 0;
                    }
                    else
                    {
                        gotoxy((selectedJ * 5) + 65, (selectedI * 5) + 11);
                        wprintf(L" ");
                        selectedI = 0;
                        selectedJ = 0;
                        score -= 1;
                        selecionou = 0;
                    }
                }
            }

            else
            {
                gotoxy((selectedJ * 5) + 65, (selectedI * 5) + 11);
                wprintf(L" ");
                selectedI = 0;
                selectedJ = 0;
                selecionou = 0;
                gotoxy(y, x);
            }
        }

        /*     if (checkVitoria()){
                gotoxy(74, 23);
                wprintf(L'PARABÉNS, VOCÊ VENCEU!');
                gotoxy(74, 28);
                wprintf(L'APERTE ESC PARA VOLTAR AO MENU');
                gotoxy(74, 32);
                printf('SUA PONTUAÇÃO FOI: {}'(score));  */
    }
}

void jogargames(){
    Reset();
    randomize();
    printtab();
    gotoxy(0, 0);
    Select();
}