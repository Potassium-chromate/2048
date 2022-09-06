#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int main(void){
    system("cls");
    printf("-----------------------\n");
    printf("-----Made By Eason-----\n");
    printf("-----------------------\n\n");
    printf("Press any key to continue");
    
    char input;
    input=getch();
    system("cls");
    int matrix[4][4]={{0,0,0,0},
                      {0,0,0,0},
                      {2,0,0,0},
                      {0,0,0,0},
                     };

    while(input!='r'){
        system("cls");
        printf("-----------------\n");
        printf("|-%d-|-%d-|-%d-|-%d-|\n",matrix[0][0],matrix[0][1],matrix[0][2],matrix[0][3]);
        printf("-----------------\n");
        printf("|-%d-|-%d-|-%d-|-%d-|\n",matrix[1][0],matrix[1][1],matrix[1][2],matrix[1][3]);
        printf("-----------------\n");
        printf("|-%d-|-%d-|-%d-|-%d-|\n",matrix[2][0],matrix[2][1],matrix[2][2],matrix[2][3]);
        printf("-----------------\n");
        printf("|-%d-|-%d-|-%d-|-%d-|\n",matrix[3][0],matrix[3][1],matrix[3][2],matrix[3][3]);
        printf("-----------------\n");

        input=getch();
    }
    return 0;
}

void up(int**matrix){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            
        }
    }
}