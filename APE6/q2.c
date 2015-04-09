#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <errno.h>

#define N 4

long global = 0;
pthread_mutex_t mutex_global;

void error(int err, char *msg)
{
        fprintf(stderr, "%s returned %d.\n", msg, err);
        fprintf(stderr, "Error message: %s.\n", strerror(errno));
        exit(EXIT_FAILURE);
}

void * inc(void * param)
{
        int err;
        for(int i=0; i<1000000; i++) {
                err = pthread_mutex_lock(&mutex_global);
                if(err!=0)
                        error(err, "pthread_mutex_lock");
                
                /* Adding this cause and infinite loop. The
                 * pthread_mutex_lock man page says :
                 * If the mutex is already locked, the calling
                 * thread shall block until the mutex becomes
                 * available. We can avoid this problem by using
                 * pthread_mutex_trylock. The man page says :
                 * The pthread_mutex_trylock() function shall
                 * be equivalent to pthread_mutex_lock(), except
                 * that if the mutex object referenced by mutex is
                 * currently locked (by any thread, including the
                 * current thread), the call shall return immediately.
                 * 
                 * En effet en utilisant try_lock comme ici en
                 * dessous ça fonctionne et le code retourne bien
                 * global = 4000000
                 */
                
                err = pthread_mutex_lock(&mutex_global);
                //err = pthread_mutex_trylock(&mutex_global);
                // Attention : trylock retourne 0 quand ça a marché!
                if(err!=0)
                //if(err==0)
                        error(err, "pthread_mutex_lock 2");

                global++;
        
                err = pthread_mutex_unlock(&mutex_global);
                if(err!=0)
                        error(err, "pthread_mutex_unlock");
                
                // Adding this returns :
                // q2: ../nptl/pthread_mutex_lock.c:80: __pthread_mutex_lock: Assertion `mutex->__data.__owner == 0' failed.
                // q2: ../nptl/pthread_mutex_lock.c:80: __pthread_mutex_lock: Assertion `mutex->__data.__owner == 0' failed.
                // Aborted (core dumped)
                
                //err = pthread_mutex_unlock(&mutex_global);
                //if(err!=0)
                //        error(err, "pthread_mutex_unlock 2");
        }

        pthread_exit(NULL);
}

int main (void)
{
        pthread_t threads[N];
        
        int err = pthread_mutex_init(&mutex_global, NULL);
        if(err!=0)
                error(err, "pthread_mutex_init");

        for(int i=0; i<N; i++) {
                err = pthread_create(&(threads[i]), NULL, &inc, NULL);
                if(err!=0)
                        error(err, "pthread_create");
        }


        for(int i=0; i<10000; i++) {}

        for(int i=N-1; i>=0; i--) {
                err = pthread_join(threads[i], NULL);
                if(err!=0)
                        error(err, "pthread_join");
        }

        err = pthread_mutex_destroy(&mutex_global);
        if(err!=0)
                error(err, "pthread_mutex_destroy");

        printf("global : %ld\n", global);

        return(EXIT_SUCCESS);
}
