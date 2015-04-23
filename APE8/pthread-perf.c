/**************************************
 * pthread-perf.c
 *
 * Programme d'exemple pour calculer le coût
 * de pthread
 *
 *************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <errno.h>

#define N 100000

/* Return t2-t1 in microseconds */
long timeval_diff(struct timeval *t2, struct timeval *t1)
{
        long diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
        return (diff);
}

void *func(void * param) {
  pthread_exit(NULL);
}


int main (int argc, char *argv[])  {
  int err;
  pthread_t thread;
  struct timeval tvStart, tvEnd;
  err=gettimeofday(&tvStart, NULL); 
  if(err!=0)
     exit(EXIT_FAILURE);

  for(int i=0;i<N;i++) {

    err=pthread_create(&(thread),NULL,&func,NULL);
    if(err!=0) {
      perror("pthread_create");
      exit(EXIT_FAILURE);
    }
    err=pthread_join(thread,NULL);
    if(err!=0) {
      perror("pthread_join");
      exit(EXIT_FAILURE);
    }
  }
   err=gettimeofday(&tvEnd, NULL);
     if(err!=0)
                       exit(EXIT_FAILURE);

       printf("pthread-perf: %ld.\n", timeval_diff(&tvEnd, &tvStart));


  return(EXIT_SUCCESS);
}

