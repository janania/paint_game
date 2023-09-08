#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "canvas.h"



/**
 * The commands file has a function for quit, help, write, add, delete, resize, save and load commands
 * There are helper functions such as which_orientation 
 * There are 4 functions that correspond to the write command (vertical, horizontal, and the diagonals)
 * This file helps with performing the commands that user wants
*/

/**
 * quit the paint program and delete canvas
  * @param c: the pointer to the canvas struct which has values for the number of rows, 
  * cols and the actual canvas itself
*/
void quit_paint(Canvas *c){
    delete_canvas(&c->canvas, c->row, c->col);
}

/**
 * prints statements that list out the possible commands so help the user 
*/
void print_help(){
  printf("Commands:\n");
  printf("Help: h\n");
  printf("Quit: q\n");
  printf("Draw line: w row_start col_start row_end col_end\n");
  printf("Resize: r num_rows num_cols\n");
  printf("Add row or column: a [r | c] pos\n");
  printf("Delete row or column: d [r | c] pos\n");
  printf("Erase: e row col\n");
  printf("Save: s file_name\n");
  printf("Load: l file_name\n");
}

/**
 * based on the given positions on the canvas, this function helps decide which kind of line
 * to write on the canvas
 * @param sr: row of starting position
 * @param sc: col of starting position
 * @param er: row of ending position
 * @param ec: col of ending position
 * @return the letter correspoding to which type of it is 
*/
char which_orientation(int sr, int sc, int er, int ec){

    //printf("sr: %d, sc: %d, er: %d, ec: %d\n", sr, sc, er, ec);
    if((sr == er) || ((sr == er) && (sc == ec))){
        return 'h';
    } else if (sc == ec){
        return 'v';
    } else if ((sc < ec && sr < er) || (ec < sc && er < sr)){
        return 'r';
    } else if((sr > er && sc < ec) || (er > sr || ec < sc) ){
        return 'l';
    }

    return ' ';
}

/**
 * places a given character on the canvas based on the given position
 * @param canvas: the 2d array representing the canvas
 * @param i: the row to be placed
 * @param j: the col to be placed
 * @param c: the char to placed 
*/
void place_character(char** canvas, int i, int j, char c){
    //printf("%c/n", canvas[i][j] );
    if(canvas[i][j] == '*'){
        canvas[i][j] = c;
    } else if (canvas[i][j] != c){
        canvas[i][j] = '+';
    }
}

/**
 * Draws a right diagonal line on the canvas
 * @param c: the pointer to the canvas struct which has values for the number of rows, 
 * cols and the actual canvas itself
 * @param sr: row of starting position
 * @param sc: col of starting position
 * @param er: row of ending position
 * @param ec: col of ending position
*/
void draw_rdiagonal(Canvas* c, int sr, int sc, int er, int ec){
    int i;
    int j;
    if(sc < ec && sr < er){
        //printf("correct loop\n");
        i = sr;
        j = sc;
        //printf("i: %d, j: %d\n", i , j );
        //printf("sr: %d, sc: %d, er: %d, ec: %d\n", sr, sc, er, ec);
        while(i <= er && j <= ec && i < c->row && j < c->col){
            //printf("i: %d, j: %d\n", i , j );
            place_character(c->canvas, i, j, '/');
            i++;
            j++;
        }
    } else {
        i = er;
        j = ec;
        while(i <= sr && j <= sc && i < c->row && j < c->col){
            place_character(c->canvas, i, j, '/');
            i++;
            j++;
    }
}
}

/**
 * Draws a left diagonal line on the canvas
 * @param c: the pointer to the canvas struct which has values for the number of rows, 
 * cols and the actual canvas itself
 * @param sr: row of starting position
 * @param sc: col of starting position
 * @param er: row of ending position
 * @param ec: col of ending position
*/

void draw_ldiagonal(Canvas* c, int sr, int sc, int er, int ec) {
    int i;
    int j;

    //printf("sr: %d, sc: %d, er: %d, ec: %d\n", sr, sc, er, ec);
    if(sr > er && sc < ec){
        //printf("correct loop\n");
        i = er;
        j = ec;
        //printf("i: %d, j: %d\n", i , j );
        //printf("sr: %d, sc: %d, er: %d, ec: %d\n", sr, sc, er, ec);
        while(i <= sr && j >= sc && i < c->row && j >= 0){
            
            place_character(c->canvas, i, j, '\\');
            i++;
            j--;
            //printf("i: %d, j: %d\n", i , j );
        }
    } else {
        i = sr;
        j = sc; 
        while(i <= er && j >= ec && i < c->row && j >= 0){
            
            place_character(c->canvas, i, j, '\\');
            i++;
            j--;
            //printf("i: %d, j: %d\n", i , j );
    }
}
}
/**
 * Draws a horizontal line on the canvas
 * @param c: the pointer to the canvas struct which has values for the number of rows, 
 * cols and the actual canvas itself
 * @param sr: row of starting position
 * @param sc: col of starting position
 * @param er: row of ending position
 * @param ec: col of ending position
*/

void draw_horizontal(Canvas* c, int sr, int sc, int er, int ec){

    //printf(" sc: %d, ec: %d\n", sc, ec);

    if(sc == ec){
        place_character(c->canvas, sr, sc, '-');
    }
    
    if(sc < ec){
        for(int i = sc; i <= ec; i++){ 
            //printf("index = [%d][%d]\n", sr, i);
            place_character(c->canvas, sr, i, '-');
        }
    } else if (sc > ec){
        //printf("correnct\n");
        for(int i = ec; i <= sc; i++){
            //printf("index = [%d][%d]\n", sr, i);
            place_character(c->canvas, sr, i, '-');
        }
    }
}

/**
 * Draws a vertical diagonal line on the canvas
 * @param c: the pointer to the canvas struct which has values for the number of rows, 
 * cols and the actual canvas itself
 * @param sr: row of starting position
 * @param sc: col of starting position
 * @param er: row of ending position
 * @param ec: col of ending position
*/

void draw_vertical(Canvas* c, int sr, int sc, int er){

    if (sr < er){
        for(int i = sr; i <= er; i++){
            //printf("index = [%d][%d]\n", i, sc);
            place_character(c->canvas, i, sc, '|');
    
        }
    } else if ( er < sr){
        for(int i = er; i <= sr; i++){
            //printf("index = [%d][%d]\n", i, sc);
            place_character(c->canvas, i, sc, '|');
        }
    }
}


/**
 * this function takes in the canvas struct and 4 ints to represent the starting ending position of the line
 * it calls on the which_orientation function to decide which line to draw
 * @param c: the pointer to the canvas struct which has values for the number of rows, 
 * cols and the actual canvas itself
 * @param sr: row of starting position
 * @param sc: col of starting position
 * @param er: row of ending position
 * @param ec: col of ending position
*/
void write(Canvas* c, int sr, int sc, int er, int ec ){
    
    char orient = which_orientation(sr, sc, er, ec);

    /*horizontal*/ 
    if (orient == 'h'){
        //printf("is horizontal\n");
        //printf("sr: %d, sc: %d, ec: %d\n", sr, sc, ec);
        draw_horizontal(c, sr, sc, er,ec);
        //print_canvas(canvas, r, c);
    } else if(orient == 'v'){
        //printf("is vertical\n");
        draw_vertical(c, sr, sc, er);
    } else if(orient == 'r'){
        //printf("right diagonal is working\n");
        draw_rdiagonal(c, sr, sc, er,ec);
    } else if(orient == 'l'){
        //printf("left diagonal is working\n");
         draw_ldiagonal(c, sr, sc, er, ec);

    } else {
        printf("coordinate points don't form a line. Please enter valid points\n");
    }

    /*left diagonal*/


}

/**
 * replaces the character at position (i,j) with a blank character
 * @param canvas: the 2d array representing the canvas
 * @param i: the row of the position
 * @param j: the col of the position
*/
void erase(char** canvas, int i, int j){
    canvas[i][j] = '*';
}

/**
 * makes a copy of the canvas to another 2d array
 * @param inC: the canvas to be copied
 * @param outC: the new canvas made from the copy
 * @param r: the number of rows of the canvas
 * @param c: the number of cols of the canvas
*/
void canvas_cpy(char** inC,char** outC, int r, int c) {
   for(int j=0; j < r; j++) {
        memcpy(outC[j], inC[j], c * sizeof(char));
   }
}


/**
 * adds a row to the given index in the canvas 
 * @param c: the pointer to the canvas struct which has values for the number of rows, 
 * cols and the actual canvas itself
 * @param pos: the index to add the row
*/
void add_row(Canvas* c, int pos){
    
    
    Canvas temp;
    temp.row = c->row;
    temp.col = c->col;
    temp.canvas = build_canvas(&temp, '*');
    canvas_cpy(c->canvas, temp.canvas,temp.row, temp.col);

    //printf("temp canvas is %c\n", temp.canvas[2][0]);

    c->row++;

    //printf("success1 :))\n");
    c = realloc_canvas(c, 'r');
    //printf("success :))\n");
    //printf(" temp canvas is %c\n", temp.canvas[2][0]);
    //print_canvas(&temp);



    int temp_i = 0;
    for(int i = 0; i < c->row; i++){
        for(int j = 0; j < c->col; j++){
            //printf("i: %d j: %d temp_i: %d\n", i, j , temp_i);
            //printf("")
            if(i == pos){
                c->canvas[i][j] = '*';
            } else{
                c->canvas[i][j] = temp.canvas[temp_i][j];
            }
        }
        if(i != pos){
            temp_i++;
        }
    }
}

/**
 * adds a col to the given index in the canvas 
 * @param c: the pointer to the canvas struct which has values for the number of rows, 
 * cols and the actual canvas itself
 * @param pos: the index to add the col
*/
void add_col(Canvas* c, int pos){
    Canvas temp;
    temp.row = c->row;
    temp.col = c->col;
    temp.canvas = build_canvas(&temp, '*');
    canvas_cpy(c->canvas, temp.canvas, temp.row, temp.col);

    //printf("temp canvas is %c\n", temp.canvas[2][0]);

    c->col++;
    c = realloc_canvas(c, 'c');
    //printf(" temp canvas is %c\n", temp.canvas[2][0]);
    //print_canvas(&temp);

    int temp_j = 0;
    for(int i = 0; i < c->row; i++){
        temp_j = 0;
        for(int j = 0; j < c->col; j++){
            //printf("i: %d j: %d temp_i: %d\n", i, j , temp_i);
            //printf("")
            if(j == pos){
                c->canvas[i][j] = '*';
            } else{
                c->canvas[i][j] = temp.canvas[i][temp_j];
                temp_j++;
            }
        }
    }


}

/**
 * fills the canvas within the given canvas struct with blank chars
 * @param c: the pointer to the canvas struct which has values for the number of rows, 
 * cols and the actual canvas itself
 * 
*/
void fill_wChar(Canvas* c){
    for(int i = 0; i < c->row; i++){
        for(int j = 0; j < c->col; j++){
            c->canvas[i][j] = '*';
        }
    }
}


/**
 * deletes the row at the given index in the canvas 
 * @param c: the pointer to the canvas struct which has values for the number of rows, 
 * cols and the actual canvas itself
 * @param pos: the index to delete the row
*/
void delete_row(Canvas* c, int pos){
    Canvas temp;
    temp.row = c->row;
    temp.col = c->col;
    temp.canvas = build_canvas(&temp, '*');
    canvas_cpy(c->canvas, temp.canvas,temp.row, temp.col);

    //printf("temp canvas is %c\n", temp.canvas[2][0]);

    c->row--;
    c = realloc_canvas(c, 'r');
    fill_wChar(c);

    //print_canvas(&temp);
    //print_canvas(c);
    //printf(" temp canvas is %c\n", temp.canvas[2][0]);
    //print_canvas(&temp);

    int temp_i = 0;
    for(int i = 0; i < c->row; i++){
        for(int j = 0; j < c->col; j++){
            //printf("i: %d j: %d temp_i: %d\n", i, j , temp_i);
            //printf("")
            //printf("canvas[%d][%d] = %c and temp.canvas[%d][%d] = %c\n", i, j, c->canvas[i][j],
             //temp_i, j, temp.canvas[temp_i][j]); 
            if(temp_i != pos){
                c->canvas[i][j] = temp.canvas[temp_i][j];

            } else if(i == pos && temp_i == pos){
                j--;
                temp_i++;
            } 
        }
            temp_i++;
        }
    }


/**
 * deletes the col at the given index in the canvas 
 * @param c: the pointer to the canvas struct which has values for the number of rows, 
 * cols and the actual canvas itself
 * @param pos: the index to delete the col
*/
void delete_col(Canvas* c, int pos){
    Canvas temp;
    temp.row = c->row;
    temp.col = c->col;
    temp.canvas = build_canvas(&temp, '*');
    canvas_cpy(c->canvas, temp.canvas, temp.row, temp.col);

    //printf("temp canvas is %c\n", temp.canvas[2][0]);

    c->col--;
    c = realloc_canvas(c, 'c');
    //printf(" temp canvas is %c\n", temp.canvas[2][0]);
    //print_canvas(&temp);

    int temp_j = 0;
    for(int i = 0; i < c->row; i++){
        temp_j = 0;
        for(int j = 0; j < c->col; j++){
            
            //printf("")
            if(j == pos){
                temp_j++; 
            }
            c->canvas[i][j] = temp.canvas[i][temp_j];
            temp_j++;
            
        }
    }


}
void resize(Canvas* c, int new_r, int new_c){

    int org_row = c->row;
    int org_col = c->col;
    c->row = new_r;
    
    c->canvas = (char**)realloc(c->canvas, sizeof(char*) * c->row);
    for(int i = org_row; i < c->row; i++){
        c->canvas[i] = (char*)malloc(sizeof(char) * c->col);
        //printf("OMG\n");
    }


    c->col = new_c;
    for(int i = 0; i < c->row; i++){
        c->canvas[i] = (char*)realloc(c->canvas[i], sizeof(char) * c->col);
        //printf("OMG\n");
    }

    for(int i = 0; i < c->row; i++){
        for(int j = 0; j < c->col; j++){
            if(i >= org_row || j >= org_col){
                c->canvas[i][j] = '*';
            }
        }
    }


}

/**
 * saves the current canvas to the file entered by the user 
 * @param c: the pointer to the canvas struct which has values for the number of rows, 
 * cols and the actual canvas itself
 * @param str: the file name the canvas should be saved in
 * @param org_row: the pointer to the int value of the number of rows in the canvas to be saved
 * @param org_cols: the pointer to the int value of the number of cols in the canvas to be saved
*/
void save_canvas(Canvas* c, char* str, int* org_row, int* org_col){
    FILE* fp;


    *org_row = c->row;
    *org_col = c->col;
    fp = fopen(str, "w");

    if (fp == NULL)  
    {  
        printf("File does not exists \n");  
        return;  
    }  

    
    for(int i = (c->row - 1); i >= 0; i--){
        fprintf(fp, "%d ", i);
        for(int j = 0; j < c->col; j++){
            //printf("i: %d j: %d\n", i, j);
            if(j == c->col-1){
                fprintf(fp, "%c\n", c->canvas[i][j]);
            } else {
                fprintf(fp, "%c ", c->canvas[i][j]);
            }
            
        }
    }

    fprintf(fp, "  ");
    for(int k = 0; k < c->col; k++){
        if( k == 0){
            fprintf(fp, "  %d ", k);
        } else if (k == c->col -1){
            fprintf(fp, "  %d\n", k);
        } else{
            fprintf(fp, "%d ", k);
        }
        
    }

    fclose(fp);

}

/**
 * loads the canvas from the file entered by the canvas
 * @param c: the pointer to the canvas struct which has values for the number of rows, 
 * cols and the actual canvas itself
 * @param str: the file name the canvas should load
 * @param org_row: the pointer to the int value of the number of rows in the canvas to be saved
 * @param org_cols: the pointer to the int value of the number of cols in the canvas to be saved
*/

void load_canvas(Canvas* c, char* str, int* org_row, int* org_col){
    FILE* fp;


    fp = fopen(str, "r");

    if (fp == NULL)  
    {  
        printf("File does not exists \n");  
        return;  
    }  

    //printf("original row: %d\n", *org_row);
    //printf("original col: %d\n", *org_col);

    resize(c, *org_row, *org_col);

    int row_n = 0;
    char x = 0;
    for(int i = *org_row - 1; i >= 0; i--){
        fscanf(fp, " %d", &row_n);
        //printf("row number: %d\n", row_n);
        for(int j = 1; j < *org_col + 1; j++){
            fscanf(fp, " %c", &x);
            //printf("number: %c\n", x);
            c->canvas[i][j-1] = x;
        }
    }


}