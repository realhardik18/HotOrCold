#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

double find_distance(int x1,int y1, int x2, int y2);

int main() {
    int GRID_SIZE;
    int tries = 0;
    printf("Your goal is to navigate to the treasure on the map\n");
    printf("Enter the size of GRID to generate: ");
    scanf("%d", &GRID_SIZE);            

    int grid[GRID_SIZE][GRID_SIZE];
    for(int x = 0; x < GRID_SIZE; x++) {
        for(int y = 0; y < GRID_SIZE; y++) {
            grid[x][y] = 0;
        }
    }
        
    srand(time(0));
    int key_x=rand()%GRID_SIZE;
    int key_y=rand()%GRID_SIZE;    
    
    for(int x = 0; x < GRID_SIZE; x++) {
        for(int y = 0; y < GRID_SIZE; y++) {
            printf("\033[38;2;0;255;0m%d \033[0m", grid[x][y]);
        }
        printf("\n");
    }

    //printf("The keycoordinates are: %d %d\n",key_x,key_y);        
    int user_x=-1;
    int user_y=-1;
    while(user_x!=key_x || user_y!=key_y){
        grid[user_x][user_y]=0;
        printf("Enter your coordinates:");
        scanf("%d %d",&user_x,&user_y);
        printf("\n");
        grid[user_x][user_y]=1;
        for(int x=0;x<GRID_SIZE;x++){
            for(int y=0;y<GRID_SIZE;y++){
                if(grid[x][y]==1){
                    printf("\033[38;2;255;0;0m%d \033[0m",grid[x][y]);                    
                }
                else{
                    printf("\033[38;2;0;255;0m%d \033[0m",grid[x][y]);
                }
                
            }
            printf("\n");
        }
        tries+=1;
        printf("the distance b/w are: %.3f\n",find_distance(user_x,user_y,key_x,key_y));
                
    }
    char exit[100];    
    printf("YOU WIN!!\n");
    printf("The treasure was at %d %d",key_x,key_y);
    printf("it took you %d tries to beat the game!",tries);
}

double find_distance(int x1,int y1, int x2, int y2){
    int x_diff=x2-x1;
    int y_diff=y2-y1;
    double distance = sqrt(pow(x_diff,2) + pow(y_diff,2));
    return distance;
}
