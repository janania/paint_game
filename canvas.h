#include <stdio.h>

#ifndef CANVAS_H
#define CANVAS_H

    
    typedef struct Canvas_struct{
        int row;
        int col;
        char** canvas;
    } Canvas;

    char** build_canvas(Canvas* c, char blank_char);
    void print_canvas(Canvas* c);
    void delete_canvas(char*** canvas, int row_dim, int col_dim);
    Canvas* realloc_canvas(Canvas* c, char which_dim);
#endif