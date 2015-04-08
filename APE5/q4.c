#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>

int * tab_init(unsigned int n) 
{
        int * tab = (int *) malloc(n*sizeof(int));
        if(tab == NULL)
                exit(EXIT_FAILURE);

        for(int i=0; i<n; i++) {
                tab[i] = 1;
        }

        return(tab);
}

void tab_free(int ** tab)
{
        free(*tab);
        *tab = NULL;
}

void tab_display(const int * tab, unsigned int n)
{
        if(tab == NULL)
                exit(EXIT_FAILURE);

        for(int i=0; i<n; i++) {
                printf("%d:\t %d\n", i, tab[i]);
        }
}

void * fthread(void * n) 
{
        if(n == NULL)
                pthread_exit(NULL);

        unsigned int * size = (unsigned int *) n;
        int * tab = tab_init(*size);
        pthread_exit((void *) tab);
}

int * getThreadRet(pthread_t th) 
{
        int *r = (int *) malloc(sizeof(int));
        int err = pthread_join(th, (void **) &r);
        if(err != 0)
                return(NULL);

        return(r);
}

int runThread(pthread_t * th, unsigned int n) 
{        
        unsigned int *arg = (unsigned int *) malloc(sizeof(unsigned int));
        *arg = n;
        int err = pthread_create(th, NULL, &fthread, (void *) &arg); 
        return(err);
}

int main(void)
{
        return(EXIT_SUCCESS);
}
