#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void up(int**matrix,int row,int col);
void all_up(int**map);
void down(int**matrix,int row,int col);
void all_down(int**map);
void left(int**matrix,int row,int col);
void all_left(int**map);
void right(int**matrix,int row,int col);
void all_right(int**map);
void gen_new(int**map);
void print_table(int**map);
void after_win(int**map,char*input);
int score(int**map);
int check_win(int**map);

int main(void){
    char input;
    system("cls");
    printf("-----------------------\n");
    printf("-----Made By Eason-----\n");
    printf("-----------------------\n\n\n");
    printf("\033[33;5m Press any key to continue\033[m\n");
    input=getch();
    
    system("cls");
    printf("****INTRODUCTION****\n");
    printf("w:go up\ns:go down\na:go left\nd:go right\n");
    printf("\033[33;5m Press any key to continue\033[m\n");
    input=getch();

    
    system("cls");
    int check=0;
    int matrix[4][4]={{0,0,0,0},
                      {0,0,0,0},
                      {0,0,0,0},
                      {2,0,0,0},
                     };
    int**map=(int**)malloc(sizeof(int*)*4);
    for(int i=0;i<4;i++){map[i]=malloc(sizeof(int)*4);}
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            map[i][j]=matrix[i][j];
            }
        }
    while(1){
        system("cls");
        print_table(map);
        printf("\n\nscore:%d\n",score(map));
        input=getch();
        if(input=='r'){break;}
        else if(input=='w'){all_up(map);}
        else if(input=='s'){all_down(map);}
        else if(input=='d'){all_right(map);}
        else if(input=='a'){all_left(map);}
        gen_new(map);
        if(check_win(map)){
            system("cls");
            printf("***YOU WIN***\n");
            printf("Want to continue?(y\\n)\n");
            input=getch();
            if(input=='y'){break;}
            else if(input=='n'){goto end;} 
            check+=check_win(map);
            break;}
    }
    if(check>0){after_win(map,&input);}
    
    end:
    system("cls");
    printf("Your total school is:%d\n\n",score(map));
    printf("\033[33;5mPress any key to end the game\033[m\n");
    input=getch();



    return 0;
}

void up(int**map,int row,int col){
    if(row>=1){
        if((map[row-1][col]==map[row][col])||(map[row-1][col]==0)){
            map[row-1][col]+=map[row][col];
            map[row][col]=0;
            up(map,row-1,col);
        }
    }
}
void all_up(int**map){
    for(int i=1;i<4;i++){
        for(int j=0;j<4;j++){
            up(map,i,j);
        }
    }
}
void down(int**map,int row,int col){
    if(row<=2){
        if((map[row+1][col]==map[row][col])||(map[row+1][col]==0)){
            map[row+1][col]+=map[row][col];
            map[row][col]=0;
            down(map,row+1,col);
        }
    }
}
void all_down(int**map){
    for(int i=2;i>=0;i--){
        for(int j=0;j<4;j++){
            down(map,i,j);
        }
    }
}
void left(int**map,int row,int col){
    if(col>=1){
        if((map[row][col-1]==map[row][col])||(map[row][col-1]==0)){
            map[row][col-1]+=map[row][col];
            map[row][col]=0;
            left(map,row,col-1);
        }
    }
}
void all_left(int**map){
    for(int j=1;j<4;j++){
        for(int i=0;i<4;i++){
            left(map,i,j);
        }
    }
}
void right(int**map,int row,int col){
    if(col<=2){
        if((map[row][col+1]==map[row][col])||(map[row][col+1]==0)){
            map[row][col+1]+=map[row][col];
            map[row][col]=0;
            right(map,row,col+1);
        }
    }
}
void all_right(int**map){
    for(int j=2;j>=0;j--){
        for(int i=0;i<4;i++){
            right(map,i,j);
        }
    }
}
void gen_new(int**map){
    srand(time(NULL));
    int x=rand()%2;

    int count=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(map[i][j]!=0){count++;}
        }
    }
    if(count==16){return;}

    else if(x==1){
        int row=rand()%4;
        int col=rand()%4;
        while(map[row][col]!=0){
            row=rand()%4;
            col=rand()%4;
        }
        map[row][col]=4;
    }
    else if(x==0){
        int row=rand()%4;
        int col=rand()%4;
        while(map[row][col]!=0){
            row=rand()%4;
            col=rand()%4;
        }
        map[row][col]=2;
    }
}
void print_table(int**map){
    for(int i=0;i<4;i++){
        printf("\n---------------------\n|");
        for(int j=0;j<4;j++)
            if(map[i][j]==0){
                printf("\033[40;30;8m%4d\033[m",map[i][j]);
                printf("|");
                }
            else if(map[i][j]!=0){
                printf("\033[40;33;5m%4d\033[m",map[i][j]);
                printf("|");
                }
        
    }
    printf("\n---------------------\n");
} 
int score(int**map){
    int score=0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){score+=map[i][j];}
    }
    return score;
}
int check_win(int**map){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(map[i][j]>=2048){return 1;}
            }
    }
    return 0;
    
}
void after_win(int**map,char*input){
    while(1){
        system("cls");
        print_table(map);
        printf("\n\nscore:%d\n",score(map));
        *input=getch();
        if(*input=='r'){break;}
        else if(*input=='w'){all_up(map);}
        else if(*input=='s'){all_down(map);}
        else if(*input=='d'){all_right(map);}
        else if(*input=='a'){all_left(map);}
        gen_new(map);
        
    }
    return;
}
