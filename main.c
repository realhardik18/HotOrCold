#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //get name of the user
    char username[100];
    printf("Welcome to HotOrCold!\n");
    printf("Enter a user name: ");
    if (scanf("%99s", username) != 1) {
        printf("Error reading username\n");
        return 1;
    }        
    return 0;
}