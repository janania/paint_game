#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "canvas.h"


/**
 * This file has functions creating, printing, deleting the canvas. It also has a function
 * to reallocate memory for the canvas so that new rows and cols can be added 
 * Its the backbone of the paint program as the canvas is where paint is played. 
*/


/**
 * builds a 2d array to represent the canvas locating the memory dynammically
 * @param c: the canvas struct which has values for the number of rows, cols and the actual canvas itself
 * @param blank_char: the character to place in each position of the canvas 
 * @return a 2d array representing the canvas filled with the given blank_char
*/

char** build_canvas(Canvas* c, char blank_char){

    c->canvas = (char**)malloc(sizeof(char*) * c->row);
    for(int i = 0; i < c->row; i++){
        c->canvas[i] = (char*)malloc(sizeof(char) * c->col);
        for(int j = 0; j < c->col; j++){

            c->canvas[i][j] = blank_char;   
        }
        
    }
    
    return c->canvas;
}


/**
 * reallocates the canvas based on the new dimensions of either the row or col 
 * if a new row or column was added, it fills it with the blank char character
 * @param c: the pointer to the canvas struct which has values for the number of rows, cols and the actual canvas itself
 * @param which_dim: the dimension (either r or c) that is being changed 
 * @return the pointer to the canvas struct;
*/
Canvas* realloc_canvas(Canvas* c, char which_dim){
    //printf("helloo!\n");
    //printf("crow: %d\n", c->row);

    c->canvas = (char**)realloc(c->canvas, sizeof(char*) * c->row);

    for(int i = 0; i < c->row; i++){
        
        c->canvas[i] = (char*)realloc(c->canvas[i], sizeof(char) * c->col);
        //printf("i: %d\n", i);
    }
    //printf("hello2 \n");
    for(int i = 0; i < c->row; i++){
        for(int j = 0; j < c->col; j++){
            if(which_dim == 'r'){
                if(i == c->row-1) {
                    //printf("i: %d, j: %d\n", i, j);
                    c->canvas[i][j] = '*';
                    //printf("i: %d, j: %d = %c ", i, j, c->canvas[i][j]);

                }
            } else if (which_dim == 'c'){
                if(j == c->col-1){
                    c->canvas[i][j] = '*';
                }
            }
            //printf("\n");
        }

        

    }
    return c;
}

/**
 * prints the canvas properly formated with the rows and cols numered
 * @param c: the pointer to the canvas struct which has values for the number of rows, cols and the actual canvas itself
*/
void print_canvas(Canvas* c) {
    /*
    Print canvas to the screen
    @canvas: the canvas to be printed
    @row_dim: the number of rows in canvas
    @col_dim: the number of columns in canvas
    @returns: nothing
    @modifies: nothing
    */

    //printf("the new row is: %d\n", c->canvas[2][0]);

    for(int i = (c->row - 1); i >= 0; i--){
        printf("%d ", i);
        for(int j = 0; j < c->col; j++){
            //printf("i: %d j: %d\n", i, j);
            printf("%c ", c->canvas[i][j]);
        }
        printf("\n");
    }

    printf("  ");
    for(int k = 0; k < c->col; k++){
        printf("%d ", k);
    }

    printf("\n");

}


void delete_canvas(char*** canvas, int row_dim, int col_dim) {
    /*
    Delete canvas AND set it to NULL.
    @canvas: the address of the canvas to be deleted
    @row_dim: the number of rows in canvas
    @col_dim: the number of columns in canvas
    @returns: nothing
    @modifies: canvas
    */
  

    for(int i = 0; i < row_dim; i++){
            //printf("%d", (*canvas)[0][0] );
            free((*canvas)[i]);
            //printf("I was here");
    }

    free(*canvas);
    *canvas = NULL;

}
