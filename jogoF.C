#include <stdio.h>
#include <wchar.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include "console.h"


void randomize();
void printpeca(int y, int x, char tipo);
void printtab(char tipo);
int removePecas();
int checkLivre(int i, int j);
void Select();

int main(){
    _setmode(_fileno(stdout), 0x00020000);
    Reset();
    randomize();
    printpeca(0, 0, '+');
    printtab('+');
    gotoxy(0, 0);
    removePecas();
    checkLivre(3, 1);
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
    int random;
    
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 8; j++){
            if (pecas[i][j]){
                tipo = '+';
                while (tipo == '+'){
                    srand(time(0));
                    random = rand() % 4;
                    if (random == 0 && a < 12){
                        a += 1;
                        tipo = '%';
                    }
                    else if (random == 1 && b < 12){
                        b += 1;
                        tipo = '$';
                    }
                    else if (random == 2 && c < 12){
                        c += 1;
                        tipo = '#';
                    }
                    else if (random == 3 && d < 12){
                        d += 1;
                        tipo = '@';
                    }
                }
                pecas[i][j] = tipo;
                wprintf(L"%c",pecas[i][j]);
            }
        }
    }
}


void printpeca(int y, int x, char tipo){
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


void printtab(char tipo){
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


int removePecas(positionY, positionX, currentY, currentX){
    pecas[positionY][positionX] == 0;
    pecas[currentY][currentX] == 0;

    Reset();
    printtab('+');
}


int checkLivre(int i, int j){
    if (j == 0 || j == 7){
        return 1;}
    else if (pecas[i][j-1] == 0){
        return 1;}
    else if (pecas[i][j+1] == 0){
        return 1;}
    else {
        printf(pecas[i][j-1]);
        return 0;}
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

    while(1){
        y = 64 + (j * 5);
        x = 11 + (i * 5);
        gotoxy(y, x);
        wprintf(L"*");

        if (_kbhit()){
            keySelect = _getch();

            if (keySelect == 0 || keySelect == 0xE0){
                keySelect = _getch();
            }
            if (keySelect == 77 && j < 7){
                j += 1;
            }
            else if (keySelect == 75 && j > 0){
                j -= 1;
            }
            else if (keySelect == 80 && i > 0){
                i -= 1;
            }
            else if (keySelect == 75 && i < 5){
                i += 1;
            }
            else if (keySelect == "r"){
                main();
            }

            else if (keySelect == 27){
                wprintf(L"PRINTAR MENU");
                break;
            }

            else if (keySelect == 13 && selecionou == 0){
                selectedI = i;
                selectedJ = j;
                selecionou = 1;
                gotoxy(y + 1, x);
                wprintf(L"o");
            }

            else if (keySelect == 13 && selecionou == 1) {
                if ((pecas[selectedI][selectedJ] == pecas[i][j]) && ((selectedI != i) && (selectedJ != j))){
                    if (checkLivre(selectedI, selectedJ) && checkLivre(i, j)){
                        removePecas(selectedI, selectedJ, i, j);
                        score += 10;
                        selecionou = 0;
                    }
                    else{
                        gotoxy((selectedJ * 5) + 65, (selectedI * 5) + 11);
                        wprintf(L" ");
                        selectedI = 0;
                        selectedJ = 0;
                        score -= 1;
                        selecionou = 0;
                    }
                }
            }

            else{
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
                wprintf(L"PARABÉNS, VOCÊ VENCEU!");
                gotoxy(74, 28);
                wprintf(L"APERTE ESC PARA VOLTAR AO MENU");
            /*  gotoxy(74, 32);
                printf("SUA PONTUAÇÃO FOI: {}"(score));  */
            
    }
}