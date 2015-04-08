#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
// Allow using getrlimit()
#include <sys/time.h>
#include <sys/resource.h>


// Global variable that threads will increment
long var = 0;

int th_count = 0;

void *inc_var(void * n)
{
        long * inc = (long *) n;
        var += (long) *inc;
        pthread_exit(NULL);
}

int main(int argc, char const **argv)
{
        if(argc != 2) {
                printf("This little program needs one argument:\n");
                printf("- The number of thread you want to create.\n");
                return(EXIT_FAILURE);
        }

        struct rlimit rl; 
        getrlimit(RLIMIT_NPROC, &rl);

        int err;
        long n = atol(argv[1]);
        long arg[n];
        pthread_t threads[n];
        for(long i=0; i<n; i++) {
                arg[i] = 1;
                err = pthread_create(&(threads[i]), NULL, &inc_var, &(arg[i]));
                if(err != 0) {
                        printf("Error %d due to pthread_create: %s.\n", err, strerror(errno));
                        printf("Maximum number of threads = %d.\n", th_count);
                        printf("And guess what?\n"); 
                        printf("This limit is the same as the one returned by getrlimit(2): %lld.\n", (long long int) rl.rlim_max);
                        printf("Hum.. Not really (but more or less!).\n");
                        return(EXIT_FAILURE);
                }
                
                th_count++;
        }

        for(long i=0; i<n; i++) {
                err = pthread_join(threads[i], NULL);
                if(err != 0) {
                        printf("Error %d due to pthread_join: %s.\n", err, strerror(errno));
                        return(EXIT_FAILURE);
                }
        }

        printf("You can go further, try creating more threads.\n");
}
