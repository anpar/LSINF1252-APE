#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char *argv[]) {
    if(argc == 4) {
        if(strcmp(argv[2], "+") == 0) { 
            printf("%d\n", atoi(argv[1]) + atoi(argv[3]));
        }
        else if(strcmp(argv[2], "-") == 0) {
            printf("%d\n", atoi(argv[1]) - atoi(argv[3]));
        }
        else if(strcmp(argv[2], "*") == 0) {
            printf("%d\n", atoi(argv[1]) * atoi(argv[3]));        
        }
        else if(strcmp(argv[2], "/") == 0) {
            printf("%d\n", atoi(argv[1]) / atoi(argv[3]));
        }
        else if(strcmp(argv[2], "%") == 0) {
            printf("%d\n", atoi(argv[1]) % atoi(argv[3]));
        }
        else {
            return(2);
        }
    }	

    return(2);
}
