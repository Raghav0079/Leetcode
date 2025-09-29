/*Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    int row[9][9] = {0};
    int col[9][9] = {0};
    int box[9][9] = {0};
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                int num = board[i][j] - '1'; // Convert char to int (0-8)
                int k = (i / 3) * 3 + (j / 3); // Calculate box index
                
                // Check if the number has already been seen in the current row, column, or box
                if (row[i][num] || col[j][num] || box[k][num]) {
                    return false;
                }
                
                // Mark the number as seen in the current row, column, and box
                row[i][num] = 1;
                col[j][num] = 1;
                box[k][num] = 1;
            }
        }
    }
    
    return true;
}