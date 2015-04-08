#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

/*
 * Pour passer plusieurs arguments à une fonction
 * via pthread_create, l'idée ici est de lui donner
 * une structure contenant plusieurs attributs
 * comme argument.
 */

struct arg_struct {
        int arg1;
        int arg2;
};

void *max(void *args)
{
        struct arg_struct *args_tmp = (struct arg_struct *) args;
        int a = args_tmp->arg1;
        int b = args_tmp->arg2;

        int *result = (int *) malloc(sizeof(int));
        if(result == NULL)
                exit(EXIT_FAILURE);

        *result = a >= b ? a : b;
        return((void *) result);
}

void error(int err, char *msg) 
{
        fprintf(stderr, "%s a retourné %d, message d'erreur : %s.\n", msg,err,strerror(errno));
        exit(EXIT_FAILURE);
}

int main(int argc, const char *argv[])
{
        if(argc != 3) {
                fprintf(stderr, "This program needs 2 arguments.\n");
                exit(EXIT_FAILURE);
        }

        pthread_t thread;
        struct arg_struct args = {atoi(argv[1]),atoi(argv[2])};
    
        int err = pthread_create(&thread, NULL, &max, &args);
        if(err != 0) {
                error(err, "pthread_create");
        }

        int *result;
        err = pthread_join(thread, (void **) &result);

        if(err != 0) {
                error(err, "phtread_join");
        }

        printf("result = %d.\n", *result);

        return(EXIT_SUCCESS);
}
