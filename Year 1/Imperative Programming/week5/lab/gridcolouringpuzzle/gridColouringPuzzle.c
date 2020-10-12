/* file    : gridColouringPuzzle.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : MON Oct 12 2020 */
/* version : 1.0 */

/* Description: This program receives as input 9x9 grid of charcaters representing colors and empty squares. Then finds the solution 
according to the rules (if possible) and prints it */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function prints the grid at the end */
void printGrid(char grid[9][9], int *a) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    *a = 1;    /* I don't want to print the message NO SOLUTION if there is one */
}

/* This function checks whether the color I'm trying to insert is possible according to the rules */
int colorPossible(int r, int c, char color, char grid[9][9]) {
    int returnValue = 1;
    int count;

    for (int k = 0; k == 0; k++) {    /* To make the program faster, I want to break and skip other tests if one was already not working */
        if (r > 0) {    /* checks whther color NORTH is the same, if statement so I won't go out of bounds */
            if (grid[r-1][c] == color) {
                returnValue = 0;
                break;
            }
        }
        if (r < 8) {    /* checks whther color SOUTH is the same, if statement so I won't go out of bounds */
            if (grid[r+1][c] == color) {
                returnValue = 0;
                break;
            }
        }
        if (c > 0) {    /* checks whther color WEST is the same, if statement so I won't go out of bounds */
            if (grid[r][c-1] == color) {
                returnValue = 0;
                break;
            }
        }
        if (c < 8) {    /* checks whther color EAST is the same, if statement so I won't go out of bounds */
            if (grid[r][c+1] == color) {
                returnValue = 0;
                break;
            }
        }
        
        /* checks whether there will be maximum 2 of the same color in a row*/
        count = 0;
        for (int i = 0; i < 9; i++) {
            if (grid[i][c] == color) {
                count++;
                if (count == 2) {    /* because I haven't inserted the color yet, it is stil '#', so if count is 2, with my inserted color it will be 3 */
                    returnValue = 0;
                    break;
                }
            }
        }
        
        /* checks whether there will be maximum 2 of the same color in a column*/
        count = 0;
        for (int j = 0; j < 9; j++) {
            if (grid[r][j] == color) {
                count++;
                if (count == 2) {   /* because I haven't inserted the color yet, it is stil '#', so if count is 2, with my inserted color it will be 3 */
                    returnValue = 0;
                    break;
                }
            }
        }
    }
    
    return returnValue;
}

/* This function finds the solution */
void solveGrid(int row, int column, char grid[9][9], char *s, int *a) {
    int r, c;

    /* if there is a solution, it will eventually come here and print it. If there is none, the function printGrid will never get called */
    if (row == 9) {
        printGrid(grid, a);
        return;
    }
    /* If column is less than 8, I want next column, if the index of column is 8, I want to move to the next row and column with index 0 */
    if (column < 8) {
        r = row;
        c = column+1;
    } else {
        r = row+1;
        c = 0;
    }
    if (grid[row][column] != '#') {    /* If it's not empty, I call the function again with next square as an input */
        solveGrid(r, c, grid, s, a);
    } else {
        for (int i = 0; i < 5; i++) {    /* Try all the colors */
            if (colorPossible(row, column, s[i], grid)) {    /* If it's possible, insert the color and call the function again */
                grid[row][column] = s[i];
                solveGrid(r, c, grid, s, a);
                grid[row][column] = '#'; /* If it didn't work later and iit comes back here with backtracking, fill the sqaure as empty */
            }
        }
    }
}


int main(int argc, char *argv[]) {
    char s[6] = "RGBYW";    /* String with possible colors */
    char grid[9][9];
    char c;
    int a = 0;    /* Passed to the function, if there is a solution -> it becomes one */

    /* fill the grid from input */
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf(" %c", &c);
            grid[i][j] = c;
        }
    }

   solveGrid(0, 0, grid, s, &a);
    if (a == 0) {    /* If a is still 0, there is no solution */
        printf("NO SOLUTION\n");
    }

    return 0;
}