#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "canvas.h"
#include "commands.h"

/**
 * This file initially builds the canvas and asks the user for the command they want to perform
 * It gets the appropriate information for based on the command and calls the appropriate function to 
 * perform the action. Paint will keep going until the user enters quit.
*/



void get_correct_inputs(int r, int c, char command, int* sr, int* sc, int* er, int* ec, char* ch, char* str){
    if(command == 'w'){
        scanf(" %d %d %d %d", sr, sc, er, ec);
    }else if (command == 'e'){
        scanf(" %d %d", sr, sc);
    }else if (command == 'a' || command == 'd'){
        scanf(" %c %d", ch, sr);
    }else if(command == 'r'){
        scanf(" %d %d", sr, sc);
    }else if(command == 's'){
        scanf(" %s", str);
    }else if(command == 'l'){
        scanf(" %s", str);
    }

}

/**
 * Based on the command that the user entered, play_paint gets the correct information 
 * and calls the appropriate function to do what the user wanted
 * @param c: its the struct canvas representing the canvas were paint is played
*/
void play_paint(Canvas* c){
    char* prompt = "Enter your command: ";
    char command;
    char ch = ' ';
    int sr = 0;
    int sc = 0;
    int er = 0;
    int ec = 0;
    char* str = (char*)malloc(sizeof(char) * 100);
    int org_row = 0;
    int org_col = 0;



    printf("%s", prompt);
    scanf(" %c", &command);

    get_correct_inputs(c->row, c->col, command, &sr, &sc, &er, &ec, &ch, str);
    


    while(command != 'q'){
        if(command == 'h'){
            print_help();
        } else if (command == 'w'){
        
            write(c, sr, sc, er, ec);
        } else if(command == 'e'){
            erase(c->canvas, sr, sc);
        } else if (command == 'a'){
            //printf("correct loop for add\n");
            //printf("ch: %c\n", ch);
            if(ch == 'c'){
                add_col(c, sr);
            }else if(ch == 'r'){
                //printf("correct loop for row\n");
                add_row(c,  sr);
                //printf("The new row dimension is %d\n", c->row);
            }
        } else if(command == 'd'){
            //printf("ch: %c\n", ch);
            if(ch == 'c'){
                delete_col(c, sr);
            }else if(ch == 'r'){
                //printf("correct loop for row\n");
                delete_row(c,  sr);
                //printf("The new row dimension is %d\n", c->row);
            }
        } else if(command == 'r'){
            //printf("working r: %d c: %d\n", sr, sc);
            resize(c, sr, sc);
        } else if(command == 's'){
            //printf("%s\n", str);
            save_canvas(c, str, &org_row, &org_col);
        } else if(command == 'l'){
            //printf("load is working\n");
            load_canvas(c, str, &org_row, &org_col);
        }

        //printf("before print\n");
        print_canvas(c);
        //printf("after print\n");
        printf("%s", prompt);
        scanf(" %c", &command);
        get_correct_inputs(c->row, c->col, command, &sr, &sc, &er, &ec, &ch, str);
    }

    quit_paint(c);

}

/**
 * based on the given row and col values, a canvas struct is created and the canvas is built
 * the canvas is then printed and then play paint is called to start the program
 * @param row: the number of rows in the canvas
 * @param col: the number of cols in the canvas
*/
void paint(int row, int col){
    Canvas c;
    c.row = row;
    c.col = col;
    c.canvas = NULL;

    c.canvas = build_canvas(&c, '*');
    print_canvas(&c);
    play_paint(&c);

}



