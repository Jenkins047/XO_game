#ifndef _TICKTACKTOE_H
#define _TICKTACKTOE_H
#endif
void drawBoard(const unsigned int, const unsigned int, char(*)[]);
char updateBoard(const unsigned int,const unsigned int, char(*)[], unsigned int, unsigned int);
unsigned int promptColumn(const unsigned int);
unsigned int promptRow(const unsigned int);
int isVictory(const unsigned int, const unsigned int, char(*)[]);
void clear(void);
void MainLoop(const unsigned int,const unsigned int, int, int*, char(*)[], int, int);
void boardInit(const int,const int, char(*)[]);
int stringToInt(const char*);