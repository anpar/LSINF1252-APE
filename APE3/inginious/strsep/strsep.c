#include <stdio.h>
#include <stdlib.h>

char *my_strsep(char **stringp, const char *delim) {
    char *str = *stringp;
    char *tok = str;

    if(str == NULL)
        return NULL;

    if(delim == NULL) {
        char *tmp = *stringp;
        *stringp = NULL;
        return tmp;
    }

    int l = 0;
    while(str[l] != 0 && str[l] != delim[0]) {
        l = l + sizeof(char);
    }

    *(str+l) = 0;
    *stringp = str+l+sizeof(char);

    return(tok);
}

int main(void)
{
    char *test = "what-the-fuck";
    char *delim = "-";
    printf("Before execution of strsep.\n");
    printf("stringp : %s.\n", test);
    printf("delim : %c.\n", delim[0]);
    char *result = my_strsep(&test, delim);
    printf("After execution of strsep.\n");
    printf("Result : %s.\n", result);
    printf("stringp : %s.", test);

    return(EXIT_SUCCESS);
}
