#include <stdio.h>
#include <stdlib.h>

char *my_strsep(char **stringp, const char *delim) {
    if(*stringp == NULL || delim == NULL)
        return NULL;

    // Computing the length of the first token
    int length = 0;
    char *runner = *stringp;
    printf("delim = %s.\n", delim);
    while(runner != 0 && runner != delim) {
        length++;
        runner = runner+1;
    }

    printf("length = %d.\n", length);

    char *token = (char *) malloc(sizeof(char)*length + 1);
    if(token == NULL)
        exit(EXIT_FAILURE);
}

int main(void)
{
    char test[] = "what-the-fuck";
    char delim = '-';
    char *result = my_strsep(&test, &delim);

    return(EXIT_SUCCESS);
}
