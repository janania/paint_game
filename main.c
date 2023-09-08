//atleast one struct
//atleast 3.h files and 2.c files
//represent the canvas with the struct 
//these are the commands that need to be implemented
//quit, help, write, add, delete, resize, save, load
/**
 * organization
 * main.c file that just calls a singular function called paint()
 * separate functions for quit, help, write, add, delete, resize, save, load
 * make empty canvas, print canvas, fill canvas 
 * day 1: get user input if no input, set row and col of canvas to 10*10
 * implement quit and help 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "canvas.h"
#include "paint.h"
#include "commands.h"


int main(int argc, char *argv[]){

    int r;
    int c;

    
    if(argc == 1){
        paint(10, 10);
    } else {
        if(argc == 3){
            r = atoi(argv[1]);
            c = atoi(argv[2]);
            if( r < 1){
                printf("The number of rows is less than 1.\n");
                printf("Making default board of 10 X 10.\n");
                paint(10, 10);
            } else if (c < 1){
                printf("The number of columns is less than 1.\n");
                printf("Making default board of 10 X 10.\n");
                paint(10, 10);
            } else {
                paint(r, c);
            }
        } else {
            printf("Wrong number of command line arguments entered.\n");
            printf("Usage: ./paint.out [num_rows num_cols]\n");
            printf("Making default board of 10 X 10.\n");
            paint(10, 10);
        }
        
        
    }

    return 0;

    
}


