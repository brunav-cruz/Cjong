#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "console.h"
#include "menu.h"

// Falta ajeitar printf/gotoxy das pecas, score, alguns {}, declarar algumas coisas (acho)

int pecas[6][8] = {{1, 1, 1, 1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1, 1, 1, 1},
                   {1, 1, 1, 1, 1, 1, 1, 1}};

void jogar()
{

    init(32);
    reset(1, 1, 32, 120);

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            pecas[6][8] = 1

                randomize();

            printtab();

            gotoxy(0, 0);

            select();
            printMenu();
        }
    }
}

void randomize()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (pecas[i][j])
            {
                char tipo = "+";
                while (tipo == "+")
                {
                    srand(time(0));
                    int random = rand() % 4;
                    if (random == 0 && a < 12)
                    {
                        a += 1;
                        tipo = "%";
                    }
                    else if (random == 1 && b < 12)
                    {
                        b += 1;
                        tipo = "$";
                    }
                    else if (random == 2 && c < 12)
                    {
                        c += 1;
                        tipo = "#";
                    }

                    else if (random == 3 && d < 12)
                    {
                        d += 1;
                        tipo = "@";
                    }
                }
                pecas[i][j] = tipo;
            }
        }
    }
}

void printpeca(y, x, tipo)
{
    /*         gotoxy((x * 5) + 62, (y * 5) + 10);
             wprint(L chr(9484) + 3 * chr(9472) + chr(9488));
            gotoxy((x * 5) + 62, (y * 5) + 11);
            wprint(L + chr(9474) + "   " + chr(9474));
            gotoxy((x * 5) + 62, (y * 5) + 12);
            wprint(L + chr(9474) + " " + tipo + " " + chr(9474));
            gotoxy((x * 5) + 62, (y * 5) + 13);
            wprint(L + chr(9474) + "   " + chr(9474));
            gotoxy((x * 5) + 62, (y * 5) + 14);
            wprint(L + chr(9492) + 3 * chr(9472) + chr(9496)); */
}

void printtab()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; i < 8; i++)
        {

            if (pecas[i][j] != 0)
            {
                tipo = pecas[i][j];
                printpeca(i, j, tipo);
            }
        }
    }
}

int checkVitoria()
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; i < 8; i++)
        {

            if (pecas[i][j] != 0)
            {
                return 0;
            }
        }

        return 1;
    }
}
void removePecas(positionY, positionX, currentY, currentX)
{
    pecas[positionY][positionX] = 0;
    pecas[currentY][currentX] = 0;

    reset();
    printtab();
}

int checkLivre(i, j)
{
    if (j == 0)
        or (j == 7)
        {
            return 1;
        }

    else if (pecas[i][j - 1] == 0)
    {
        return 1;
    }

    else if (pecas[i][j + 1] == 0)
    {
        return 1;
    }

    else
        printf(pecas[i][j - 1])
        {
            return 0;
        }
}

int score = 0

    void
    select()
{
    int x = 0;
    int y = 0;
    int selectedI = 0;
    int selectedJ = 0;
    int selecionou = 0;
    int i = 0;
    int j = 0;
    int keySelect = 0 while (1)
    {
        y = 64 + (j * 5);
        x = 11 + (i * 5);
        gotoxy(y, x);
        printf("*");

        keySelect = _getch();
        if (_kbhit())
        {
            if (keySelect == 0 || keySelect == 0xE0)
                keySelect = _getch();
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
            else if (keySelect == 'r'):
                jogar();

            else if (keySelect == 27):
                printMenu();
            break

                else if (keySelect == 13 && selecionou == 0)
            {
                selectedI = i;
                selectedJ = j;
                selecionou = 1;
            }
            gotoxy(y + 1, x);
            printf("o");

            else if (keySelect == 13 and selecionou == 1) : if ((pecas[selectedI][selectedJ] == pecas[i][j]) && ((selectedI != i) && (selectedJ != j)))
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
                    printf(" ");
                    selectedI = 0;
                    selectedJ = 0;
                    score -= 1;
                    selecionou = 0;
                }
            }
            else
            {
                gotoxy((selectedJ * 5) + 65, (selectedI * 5) + 11)
                    printf(" ")
                        selectedI = 0;
                selectedJ = 0;
                selecionou = 0;
            }
        }
        gotoxy(y, x);
        print(" ");
        if (checkVitoria())
        {
            gotoxy(74, 23);
            printf((10, 255, 10) + 'PARABÉNS, VOCÊ VENCEU!');
            gotoxy(74, 28);
            printf((10, 255, 10) + 'APERTE ESC PARA VOLTAR AO MENU');
            gotoxy(74, 32);
            printf((10, 255, 10) + 'SUA PONTUAÇÃO FOI: {}'(score));
        }
    }
}