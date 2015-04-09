#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

#define SUDOKU_SIZE 9

typedef struct {
        int grid[SUDOKU_SIZE][SUDOKU_SIZE];
} sudoku_t;


/*
 * Check if one row is correct.
 */
bool rowchecker(int * row)
{
        bool in[10] = {false};
}

/*
 * Check if one column is correct.
 */
bool colchecker(int * col) 
{
        
}

/*
 * Check if one square is correct.
 */
bool checksquare(int * square)
{
        
}

void sudoku_solve(sudoku_t * s, int nthread)
{
        
}

int main(int argc, const char **argv) 
{        
        return(EXIT_SUCCESS);
}
