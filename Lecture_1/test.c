#include<stdio.h>

void menu(){
    printf("Please choose the status: 1. play 2. exit\n");
    printf("-----------------------------------------\n");
}

void start(){
    int input = 0;
    do{
        menu();
        printf("please enter your input: \n");
        scanf("%d",&input);
        switch(input){
            case 1:
                //game();
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