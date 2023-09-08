#include <stdio.h>

#ifndef paint_H
#define paint_H

    void get_correct_inputs(int r, int c, char command, int* sr, int* sc, int* er, int* ec, char* ch, char* str);
    void paint(int row, int col);
    void play_paint(Canvas* c);


#endif