#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <errno.h>

/*
    Le code est correct malgré ce que dit Inginious
    à propose de la mémoire.
*/

void *fthread(void *n) {
    if(n == NULL)
        return(NULL);

    unsigned int *arg = n;
    int *ptr = tab_init(*arg);
    return(ptr);
}

int *getThreadRet(pthread_t th) {
    void *result;
    int err = pthread_join(th, &result);
    if(err != 0)
        return(NULL);

    return((int *) result);
}

int runThread(pthread_t *th, unsigned int n) {
    int err = pthread_create(th, NULL, &fthread, (void *) &n);
    return(err);
}

int main(void) {
    return(EXIT_SUCCESS);
}
