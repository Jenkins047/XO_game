#ifndef _STDIO_H
#include <stdio.h>
#endif
#ifndef _TICKTACKTOE_H
#include "310697_tickTackToe.h"
#endif
#include <math.h>
#include <string.h>

void drawBoard(const unsigned int HEIGHT, const unsigned int WIDTH, char (*board)[WIDTH])
{
    int i=0,j=0;
    const int LINE_LEN = 2*WIDTH+3;
    
    /*Print header*/
    printf("  ");
    for(i = 2;i < LINE_LEN - 1;i++)
    {
        if(i % 2 == 0)
            printf("%d",((i-1)/2)+1);
        else
            printf("%c",' ');
    }
    printf("\n");
    
    for(i=0;i<2*HEIGHT;i++)
    {
        if(i%2 == 1)
            printf("%d",((i+2)/2));
        for(j=1;j < LINE_LEN - 1;j++)
        {
            
            if(i%2==0)
            {
                printf(" ");
                printf(" ");
                
            }
            else
            {
                
                if(j % 2 == 1)
                    printf(" ");
                else
                    /**(line + j)=board[(i-1)/2][(j-1)/2];*/
                    printf("%c", *(*(board + ((i-1)/2)) + ((j-1)/2)));
            }
           
        }
        printf("\n");
    }
}

char updateBoard(const unsigned int HEIGHT, const unsigned int WIDTH, char (*board)[WIDTH], unsigned int x, unsigned int y)
{
    if(*(*(board+y-1)+x-1)=='o')
        *(*(board+y-1)+x-1)='x';
    else
        *(*(board+y-1)+x-1)='o';

    if(x-1>=1)
    {
        if(*(*(board+y-1)+x-2)=='o')
            *(*(board+y-1)+x-2)='x';
        else
            *(*(board+y-1)+x-2)='o';
    }

    if(x+1<=WIDTH)
    {
        if(*(*(board+y-1)+x)=='o')
            *(*(board+y-1)+x)='x';
        else
            *(*(board+y-1)+x)='o';
    }

    if(y-1>=1)
    {
        if(*(*(board+y-2)+x-1)=='o')
            *(*(board+y-2)+x-1)='x';
        else
            *(*(board+y-2)+x-1)='o';
    }

    if(y+1<=HEIGHT)
    {
        if(*(*(board+y)+x-1)=='o')
            *(*(board+y)+x-1)='x';
        else
            *(*(board+y)+x-1)='o';
    }
}

unsigned int promptRow(const unsigned int HEIGHT)
{
    unsigned int buf=0;      
    do
    {
        printf("Podaj nr. wiersza: ");
        scanf("%d",&buf);
        if(!(1<=buf && buf<=HEIGHT))
            {
                printf("Nie ma takiego numeru wiersza!\n");
                clear();
            }
    }while(!(1<=buf && buf<=HEIGHT));
    clear();
    return buf;
}

unsigned int promptColumn(const unsigned int WIDTH)
{
    unsigned int buf=0;      
    do
    {
        
        printf("Podaj nr. kolumny: ");
        scanf("%d",&buf);
        if(!(1<=buf && buf<=WIDTH))
            {
                printf("Nie ma takiego numeru kolumny!\n");
                clear();
            }
    }while(!(1<=buf && buf<=WIDTH));
    return buf;
}

int isVictory(const unsigned int WIDTH, const unsigned int HEIGHT, char (*board)[WIDTH])
{
    int i=0,j=0;
    for(i=0;i<HEIGHT;i++)
    {
        for(j=0;j<WIDTH;j++)
        {
            if(*(*(board+i)+j)=='o')
                return 0;
        }
    }
    return 1;
}

void clear (void)
{    
  while ( getchar() != '\n' );
}

void MainLoop(const unsigned int HEIGHT, const unsigned int WIDTH, int victory, int *movesCounter, char (*board)[WIDTH], int rowNumber, int columnNumber)
{
    while(!victory)
        {
            drawBoard(HEIGHT, WIDTH, board);
            
            printf("Liczba ruchow: %d\n",*movesCounter);
            
            rowNumber = promptRow(HEIGHT);
            columnNumber = promptColumn(WIDTH);
            
            updateBoard(HEIGHT, WIDTH, board, columnNumber, rowNumber);
            victory = isVictory(HEIGHT, WIDTH, board);
            ++*movesCounter;
        }
}

void boardInit(int WIDTH, int HEIGHT, char (*board)[WIDTH])
{
    int i=0, j=0;
        for(i=0;i < HEIGHT;i++)
        {
            for(j=0;j < WIDTH;j++)
                *(*(board+i)+j) = 'o';
                /*board[i][j]='o';*/
        }
}

int stringToInt(const char* arg)
{
    int sum = 0, i = strlen(arg), j = 0;
    if(strlen(arg) == 1)
        return *arg - '0';
    else
    {
        for(i = strlen(arg)-1;i >= 0;i--)
        {
            sum += pow(10,i)*(*(arg+j)-'0');
            j++;
        }
    }
    return sum;
}