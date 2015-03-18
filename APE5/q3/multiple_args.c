#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

struct arg_struct {
    int arg1;
    int arg2;
};

void *max(void *args)
{
    // Cast args in a arg_struct
    struct arg_struct *args_tmp = (struct arg_struct *) args;
    int a = args_tmp->arg1;
    int b = args_tmp->arg2;
    int *result = (int *) malloc(sizeof(int));

    if(result == NULL)
        exit(EXIT_FAILURE);

    result = a >= b ? &a : &b;
    return((void *) result);
}

int main(void)
{
    pthread_t thread;
    struct arg_struct args;
    args.arg1 = 5;
    args.arg2 = 4;
    int err = pthread_create(&thread, NULL, &max, &args);

    if(err != 0)
    {
        printf("pthread_create failure, err = %d.\n", err);
        exit(EXIT_FAILURE);
    }

    int *result;
    err = pthread_join(thread, (void **) &result);

    if(err != 0)
    {
        printf("pthread_join failure, err = %d.\n", err);
        exit(EXIT_FAILURE);
    }

    printf("result = %d.\n", *result);

    return(EXIT_SUCCESS);
}
