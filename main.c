#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STRING_H
#include <string.h>
#endif

#ifndef _TICKTACKTOE_H
#include "310697_tickTackToe.h"
#endif

int main(int argc, char *argv[])
{
    if((!strcmp(*argv, "c:\\Users\\Szymon\\Documents\\Studia\\21Z\\PROS\\LAB\\LAB4\\310697_main.exe") || 
       !strcmp(*argv,".\\310697_main.exe")) && argc == 3)
    {

        const unsigned int WIDTH = stringToInt(*(argv+1)), HEIGHT = stringToInt(*(argv+2));

        char board[HEIGHT+1][WIDTH+1]; 
        int rowNumber=0, 
            columnNumber=0, 
            victory=0, 
            movesCounter=0;
        
        boardInit(HEIGHT, WIDTH, board);

        MainLoop(HEIGHT, WIDTH, victory, &movesCounter, board, rowNumber, columnNumber);
        
        drawBoard(HEIGHT, WIDTH, board);
        puts("Wygrana!");
        printf("Ilosc ruchow: %d", movesCounter);
        getchar();
    }
    else
    {
        if(argc < 3 || argc > 3)
        {
            printf("Przykladowe uzycie .\\310697_main.exe <liczba kolumn> <liczba wierszy>");
            return 1;
        }
        else
        {
            puts("Error: Name of executable changed");
            printf(*argv);
            getchar();
            return -1;
        }
    }
    return 0;
}