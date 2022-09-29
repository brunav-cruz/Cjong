#include <stdio.h>
#include <wchar.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include "console.h"
#include "jogoF.h"


void printMenu();
void menuChoice();

int main(){
     _setmode(_fileno(stdout), 0x00020000);
    Reset();
    printMenu();
    menuChoice();
    return 0;
    
}

void printMenu(){
    gotoxy(0,1);
    wprintf(L"────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────");

    gotoxy(78,10);
    wprintf(L"┌────────────┐");
    gotoxy(83,11);
    wprintf(L"MENU");
    gotoxy(78, 11);
    wprintf(L"│");
    gotoxy(91,11);
    wprintf(L"│");
    gotoxy(78,12);
    wprintf(L"└────────────┘");

    gotoxy(38,19);
    wprintf(L"┌───────────────┐");
    gotoxy(41,20);
    wprintf(L"1. JOGAR");
    gotoxy(38,20);
    wprintf(L"│");
    gotoxy(54,20);
    wprintf(L"│");
    gotoxy(38,21);
    wprintf(L"└───────────────┘");

    gotoxy(76,19);
    wprintf(L"┌───────────────┐");
    gotoxy(79,20);
    wprintf(L"2. REGRAS");
    gotoxy(76,20);
    wprintf(L"│");
    gotoxy(92,20);
    wprintf(L"│");
    gotoxy(76,21);
    wprintf(L"└───────────────┘");

    gotoxy(116,19);
    wprintf(L"┌───────────────┐");
    gotoxy(120,20);
    wprintf(L"3. SAIR");
    gotoxy(116,20);
    wprintf(L"│");
    gotoxy(132,20);
    wprintf(L"│");
    gotoxy(116,21);
    wprintf(L"└───────────────┘");

    gotoxy(0,40);
    wprintf(L"────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────");

    gotoxy(75, 28);
    menuChoice(0);

}

void menuChoice(){
    int option;
    wprintf(L"ESCOLHA UMA OPCAO: ");
    wscanf(L"%d", &option);

    while(1){
        if(option == 1){
            Reset();
            jogargames();
            break;
        }else if(option == 2){
            Reset();
            break;
        }else if(option == 3){
            Reset();
            break;
        }else if(option == 4){
            Reset();
        }else{
            printMenu();
            break;
        }
    return;
    }
}
