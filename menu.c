#include <stdio.h>
#include<stdbool.h>
#include <conio.h>
#include <wchar.h>
#include <windows.h>
#include <stdlib.h>
#include "console.h"

void main(){
    reset();
    gotoxy(5,5);
    wprintf(L"ablulbe");
}

void printMenu(){
    gotoxy(3,1);
    wprinf(L"────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────");

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

    gotoxy(3,40);
    wprinf(L"────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────");

    gotoxy(75, 28);
    menuChoice(0);

}

void clearConsole(){
    system('cls');
}

void menuChoice(option){
    int option;
    wprintf("ESCOLHA UMA OPÇÃO: ");
    scanf("%d", &option);
    while(option == 0){
        option = controle();
    }

    while(true){
        if(option == 1){
            system('cls');
            /* dificuldade.printDif(); */
            break;
        } elif(option == 2){
            system('cls');
        }elif(option == 3){
            system('cls');
        }elif(option == 4){
            system('cls');
        }else{
            printMenu();
            break;
        }
    return;
    }
}

void controle(){
    getch_select = getch.read_event();
    if(getch_select.event_type == getch.KEY_DOWN){
        if(getch_select.name == '1'){
            return 1;
        }
        if(getch_select.name == '2'){
            return 2;
        }
        if(getch_select.name == '3'){
            return 3;
        }
        if(getch_select.name == '4'){
            return 4;
        }
    }
}
