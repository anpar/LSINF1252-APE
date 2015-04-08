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

        sudoku_t *s;
        // TODO : faire une fonction qui retourne un sudo
        // à partir d'un fichier.
        s->grid = {     {0,7,0,2,4,0,9,0,8},
                        {4,0,9,3,0,0,2,0,0},
                        {5,0,1,9,6,8,0,0,0},
                        {7,0,0,0,0,0,4,2,0},
                        {0,0,0,0,0,0,0,0,0},
                        {0,1,4,0,0,0,0,0,3},
                        {0,0,0,4,5,9,3,0,2},
                        {0,0,7,0,0,1,5,0,9},
                        {9,0,2,0,3,6,0,4,0}     };
        

        return(EXIT_SUCCESS);
}
