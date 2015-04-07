#include <stdio.h>
#include <stdlib.h>

int a[3][3] = { {1,2,3},
                {4,5,6},
                {7,8,9} };

/*
 * display prints every elements of a and their addresses
 * in order to know if they are stored line by line or
 * row by row.
 */
void display()
{
   for(int l=0; l<3; l++) {
        for(int c=0; c<3; c++) {
                printf("%d (addr: %p)\t", a[l][c], &a[l][c]);                
        }
        printf("\n");
   }
}

int main(void) {
        display();
        /*
         * We can clearly see now that a is stored line by line
         * like this:
         * address      | value
         * ---------------------------
         * 0x601080     | 9
         * 0x60107c     | 8
         * 0x601078     | 7
         * ox601074     | 6
         * 0x601070     | 5
         * 0x60106c     | 4
         * 0x601068     | 3
         * 0x601064     | 2
         * 0x601060     | 1
         */
        return(EXIT_SUCCESS);
}
