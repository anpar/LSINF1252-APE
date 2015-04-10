/**************************************
 * pthread-philo-sem.c
 *
 * Programme d'exemple de pthread avec
 * philosophes qui dinent et sÃ©maphores
 *
 **************************************/

///AAA
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define PHILOSOPHES 3

pthread_t phil[PHILOSOPHES];
sem_t baguette[PHILOSOPHES];
pthread_t observer;

void mange(int id) {
  printf("Philosophe [%d] mange\n",id);
  for(int i=0;i< rand(); i++) {
    // philosophe mange
  }
}

void* philosophe ( void* arg )
{
  int *id=(int *) arg;
  int left = *id;
  int right = (left + 1) % PHILOSOPHES;
  while(true) {
    printf("Philosophe [%d] pense\n",*id);
    sem_wait(&baguette[left]);
    printf("Philosophe [%d] possede baguette gauche [%d]\n",*id,left);
    sem_wait(&baguette[right]);
    printf("Philosophe [%d] possede baguette droite [%d]\n",*id,right);
    mange(*id);
    sem_post(&baguette[left]);
    printf("Philosophe [%d] a libere baguette gauche [%d]\n",*id,left);
    sem_post(&baguette[right]);
    printf("Philosophe [%d] a libere baguette droite [%d]\n",*id,right);
  }
  return (NULL);
}

bool compare(int tab1[3], int tab2[3])
{
        for(int i=0; i<3; i++) {
                if(tab1[i] != tab2[i])
                        return(false);
        }

        return(true);
}

void * observe(void * param)
{
        int old[3] = {0, 0, 0};
        int new[3];
        while(true) {
                sem_getvalue(&baguette[0], &new[0]);
                sem_getvalue(&baguette[1], &new[1]);
                sem_getvalue(&baguette[2], &new[2]);

                if(compare(new, old)) {
                        printf("Semaphore didn't change during 10s.\n");
                        exit(EXIT_FAILURE);
                }

                *old = *new;
                sleep(10);
        }

        pthread_exit(NULL);
}

///BBB
int main ( int argc, char *argv[])
{       
        long i;
        int id[PHILOSOPHES];
        
        srand(getpid());

        pthread_create(&observer, NULL, observe, NULL);

        for (i = 0; i < PHILOSOPHES; i++)
                id[i]=i;

        for (i = 0; i < PHILOSOPHES; i++)
                sem_init( &baguette[i], 0 , 1);

        for (i = 0; i < PHILOSOPHES; i++)
                pthread_create(&phil[i], NULL, philosophe, (void*)&(id[i]) );

        for (i = 0; i < PHILOSOPHES; i++)
                pthread_join(phil[i], NULL);

        pthread_join(observer, NULL);
        
        return (EXIT_SUCCESS);
}
