#include <stdio.h>

#ifndef COMMANDS_H
#define COMMANDS_H
    void quit_paint(Canvas* c);
    void print_help();
    void draw_horizontal(Canvas* c, int sr, int sc, int ec);
    void draw_vertical(Canvas* c, int sr, int sc, int er);
    void draw_rdiagonal(Canvas* c, int sr, int sc, int er, int ec);
    void draw_ldiagonal(Canvas* c, int sr, int sc, int er, int ec);
    void place_character(char** canvas, int i, int j, char c);
    char which_orientation(int sr, int sc, int er, int ec);
    void erase(char** canvas, int i, int j);
    void write(Canvas* c, int sr, int sc, int er, int ec);
    void add_row(Canvas* c, int pos);
    void add_col(Canvas* c, int pos);
    void delete_row(Canvas* c, int pos);
    void delete_col(Canvas* c, int pos);
    void resize(Canvas * c, int new_r, int new_c);
    void save_canvas(Canvas* c, char* str, int* org_row, int* org_col);
    void load_canvas(Canvas* c, char* str, int* org_row, int* org_col);


#endif