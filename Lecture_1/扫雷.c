#include <stdio.h>
#include "扫雷.h"

void menu(){
    printf("Please choose the status: 1. play 2. exit\n");
    printf("-----------------------------------------\n");
}

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set){
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++){
        for (j = 0; j < cols; j++){
            board[i][j] = set;
        }
    }
}
int CountBombs(char board[ROWS][COLS],int x,int y){
    return board[x-1][y] + board[x-1][y-1] + board[x-1][y+1] + board[x+1][y-1] + board[x+1][y] 
    + board[x+1][y + 1] + board[x][y+1] + board[x][y-1] - 8*'0';
}


void SetBomb(char board[ROWS][COLS], int rows, int cols){
    int count = EASY_LEVEL;
    while(count){
        int x = rand() % rows + 1;
        int y = rand() % cols + 1;

        if(board[x][y] == '0'){
            board[x][y] = '1';
            count --;
        }
    }
}

void CheckOutBomb(char mine[ROWS][COLS],char show[ROWS][COLS],int rows, int cols){
    int x = 0;
    int y = 0;
    int win = 0;
    while(win < rows * cols - EASY_LEVEL
    
    ){
        printf("Coordniater: ");
        scanf("%d %d",&x,&y);
        if (x >=1 && x<= rows && y >=1 && y <= cols){
            if (mine[x][y] == '1'){
                printf("It is a Bomb\n");
                DisplayBoard(mine, rows, cols);
                break;
            } else{
                int n = CountBombs(mine,x,y);
                show[x][y] = n + '0';
                DisplayBoard(show,rows,cols);
                win ++;
            }
        }else{
            printf("invalid input. Please input again\n");
        }
    }
    if (win == rows * cols - EASY_LEVEL){
        printf("WIN\n");
    }
}

void game(){
    char mine[ROWS][COLS] = {0};
    char show[ROWS][COLS] = {0};

    InitBoard(mine, ROWS, COLS, '0');
    InitBoard(show, ROWS, COLS, '*');
    SetBomb(mine,ROW,COL);
    DisplayBoard(mine,ROW,COL);
    DisplayBoard(show,ROW,COL);

    CheckOutBomb(mine,show,ROW,COL);
}


void DisplayBoard(char board[ROWS][COLS], int row, int col){
    int i = 0;
    int j = 0;
    //Column number
    for (i = 0; i <= col; i++){
        printf("%d ",i);
    }
    printf("\n");
    for (i = 1; i <= row; i++){
        printf("%d ", i);
        for (j = 1; j <= col; j++){
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}


void start(){
    int input = 0;
    srand((unsigned int)time(NULL));
    do{
        menu();
        printf("please enter your input: \n");
        scanf("%d",&input);
        switch(input){
            case 1:
                game();
                break;
            case 0:
                printf("Exiting the game.......\n");
                break;
            default:
                printf("Wrong input\n");
                break;
        }
    }while(input);
}

int main()
{
    start();
    return 0;
}