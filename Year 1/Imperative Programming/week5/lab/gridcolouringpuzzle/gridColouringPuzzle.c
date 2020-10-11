/* file    : gridColouringPuzzle.c */
/* author  : Matej Priesol (email: m.priesol@student.rug.nl) */
/* date    : TUE Oct 6 2020 */
/* version : 1.0 */

/* Description:  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printGrid(char grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
}

int colorPossible(int r, int c, char color, char grid[9][9]) {
    int returnValue = 1;
    int count;

    for (int k = 0; k == 0; k++) {
        if (r > 0) {
            if (grid[r-1][c] == color) {
                returnValue = 0;
                break;
            }
        }
        if (r < 8) {
            if (grid[r+1][c] == color) {
                returnValue = 0;
                break;
            }
        }
        if (c > 0) {
            if (grid[r][c-1] == color) {
                returnValue = 0;
                break;
            }
        }
        if (c < 8) {
            if (grid[r][c+1] == color) {
                returnValue = 0;
                break;
            }
        }
        
        count = 0;
        for (int i = 0; i < 9; i++) {
            if (grid[i][c] == color) {
                count++;
                if (count == 2) {
                    returnValue = 0;
                    break;
                }
            }
        }
        
        count = 0;
        for (int j = 0; j < 9; j++) {
            if (grid[r][j] == color) {
                count++;
                if (count == 2) {
                    returnValue = 0;
                    break;
                }
            }
        }
    }
    
    return returnValue;
}

void solveGrid(int row, int column, char grid[9][9], char *s) {
    int r, c;

    if (row == 9) {
        printGrid(grid);
        return;
    }
    /* recursive case: compute next square (r,c) */
        if (column < 8) {
    /* Next square is (row,column+1) */
        r = row;
        c = column+1;
    } else {
        /* Next square is (row+1,0) */
        r = row+1;
        c = 0;
    }
    if (grid[row][column] != '#') {
        /* There is already a digit here, continue */
        solveGrid(r, c, grid, s);
    } else { /* Empty square. Try all possible digits */
        for (int i = 0; i < 5; i++) {
            if (colorPossible(row, column, s[i], grid)) {
                grid[row][column] = s[i]; /* fill in digit, and recurse */
                solveGrid(r, c, grid, s);
                grid[row][column] = '#'; /* clear square */
            }
        }
    }
}


int main(int argc, char *argv[]) {
    char s[6] = "RGBYW";
    char grid[9][9];
    char c;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            scanf(" %c", &c);
            grid[i][j] = c;
        }
    }

    solveGrid(0, 0, grid, s);

    return 0;
}