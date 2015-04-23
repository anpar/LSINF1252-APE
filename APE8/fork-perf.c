/**************************************
 * fork-perf.c
 *
 * Programme d'exemple pour calculer le coût
 * de fork
 *
 *************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/time.h>
#include <errno.h>

#define N 100000

/* Return t2-t1 in microseconds */
long timeval_diff(struct timeval *t2, struct timeval *t1)
{
        long diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
        return (diff);
}

int main (int argc, char *argv[])  {
  int status;
  pid_t pid;
  struct timeval tvStart, tvEnd;
  int err;

  err=gettimeofday(&tvStart, NULL);
  if(err!=0)
          exit(EXIT_FAILURE);

  for(int i=0;i<N;i++) {
    pid=fork();
    if (pid==-1) {
      // erreur à l'exécution de fork
      perror("fork");
      exit(EXIT_FAILURE);
    }
    // pas d'erreur
    if (pid==0) {
      return(EXIT_SUCCESS);
    }
    else {
      int fils=waitpid(pid,&status,0);
      if(fils==-1) {
	perror("wait");
	exit(EXIT_FAILURE);
      }
      if(!WIFEXITED(status)) {
	fprintf(stderr,"Erreur de waitpid\n");
	exit(EXIT_FAILURE);
      }
    }
  }

  err=gettimeofday(&tvEnd, NULL);
  if(err!=0)
          exit(EXIT_FAILURE);

  printf("fork-perf: %ld.\n", timeval_diff(&tvEnd, &tvStart));

  return(EXIT_SUCCESS);
}

