#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Simpler version of strsep where delim is only
 * 1 character.
 */
char *my_strsep(char **stringp, const char *delim) {
        //printf("stringp points toward %p.\n", *stringp);
        //printf("stringp+1 gives: %s.\n", *(stringp)+1);
        //printf("while stringp[1] gives : %c.\n", (*stringp)[1]);
        //(*stringp)[5] = 0;
        //printf("after stringp[5] = 0, stringp gives %s.\n", *stringp);

        if(*stringp == NULL) 
                return(NULL);
        
        char *token = *stringp;
        int i;
        for(i=0; (*stringp)[i] != 0; i++) {
                if((*stringp)[i] == delim[0]) {
                        *stringp = *(stringp)+i+1;
                        //printf("1: *stringp = %s.\n", *stringp); // print the-fuck as desired
                        (*stringp)[-1] = 0;
                        //printf("2: *stringp = %s.\n", *stringp); // idem
                        //printf("3: token = %s.\n", token);
                        return(token);
                }
        }
        
        *stringp = NULL;
        return(token);
}

int main(void)
{
        char string[] = "what-the-fuck";
        const char delim[] = "-";
        char *ptr = &string[0];
        char **dptr = &ptr;

        printf("Before my_strsep :\n");
        printf("string = %s.\n", string);
        char *token = my_strsep(dptr, delim);
        printf("After my_strsep :\n");
        printf("string = %s.\n", ptr);
        printf("token = %s.\n", token);
        /*
         * Results :
         * Before my_strsep :
         * string = what-the-fuck.
         * After my_strsep :
         * string = the-fuck.
         * token = what.
         *
         * So it seems correct. Problem is that I'm using a
         * little trick with prt and dptr to avoid segmentation
         * fault when replacing the delimiter by 0. In every strsep
         * usage example I see, they use strdupa to make string editable.
         */
}
