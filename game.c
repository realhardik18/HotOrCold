#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <conio.h>

int find_distance(int x1,int y1, int x2, int y2);

int main() {
    //get name of the user
    /*char username[100];
    printf("Welcome to HotOrCold!\n");
    printf("Enter a user name: ");
    if (scanf("%99s", username) != 1) {
        printf("Error reading username\n");
        return 1;
    }*/
    
    //generating grid
    int GRID_SIZE;
    printf("Enter the size of GRID to generate: ");
    scanf("%d", &GRID_SIZE);            

    int grid[GRID_SIZE][GRID_SIZE];
    for(int x = 0; x < GRID_SIZE; x++) {
        for(int y = 0; y < GRID_SIZE; y++) {
            grid[x][y] = 0;
        }
    }
    
    //generating key cordinates
    srand(time(0));
    int key_x=rand()%GRID_SIZE;
    int key_y=rand()%GRID_SIZE;
    grid[key_x][key_y]=1;

    //showing the grid to user
    for(int x = 0; x < GRID_SIZE; x++) {
        for(int y = 0; y < GRID_SIZE; y++) {
            printf("\033[38;2;0;128;0m%d \033[0m", grid[x][y]);
        }
        printf("\n");
    }
    printf("THe keycoordinates are: %d %d\n",key_x,key_y);    
    printf("the distance b/w are: %d",find_distance(0,0,key_x,key_y));

    //exit procedure
    char exit[100];    
    printf("game over! enter a key to exit: ");
    if (scanf("%99s", exit) != 1) {
        printf("Error reading username\n");
        return 1;
    }

}

int find_distance(int x1,int y1, int x2, int y2){
    int x_diff=x2-x1;
    int y_diff=y2-y1;
    int distance = sqrt((x_diff,2) + pow(y_diff,2));
    return distance;
}