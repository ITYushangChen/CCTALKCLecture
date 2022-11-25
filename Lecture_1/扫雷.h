#include <time.h>
#include <stdlib.h>
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_LEVEL 80
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);
void DisplayBoard(char board[ROWS][COLS], int rows, int cols);
void SetBomb(char board[ROWS][COLS],int rows, int cols);
void CheckOutBomb(char mine[ROWS][COLS],char show[ROWS][COLS],int rows, int cols);