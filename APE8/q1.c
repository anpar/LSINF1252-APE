/*
 * D'après la man page de fork, les erreurs suivantes sont
 * possibles :
 * EAGAIN
 * fork() cannot allocate sufficient memory to copy the
 * parent's page tables and allocate a task structure for
 * the child.
 * EAGAIN
 * It was not possible to create a new process because the
 * caller's RLIMIT_NPROC resource limit was encountered. To
 * exceed this limit, the process must have either the 
 * CAP_SYS_ADMIN or the CAP_SYS_RESOURCE capability.
 * ENOMEM
 * fork() failed to allocate the necessary kernel structures
 * because memory is tight.
 *
 * L'erreur la plus facile à obtenir est sans doute EAGAIN,
 * construisons une boucle qui forke à l'infini!
 *
 * EDIT: Bravo, tu viens de lancer une fork bomb sur ton
 * propre PC #genius !
 * L'erreur retournée est "Ressource temporary unavailable".
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
        if(argc != 2) {
                printf("Usage: %s n", argv[0]);
                printf("\t where n is the number of fork().\n");
                return(EXIT_FAILURE);
        }

        pid_t pid;
        for(long i = 0; i < atol(argv[1]); i++) {
                pid = fork();
                if(pid == -1) {
                        perror("fork");
                        exit(EXIT_FAILURE);
                }

                if(pid == 0) {
                        printf("Processus : %d, père : %d\n", getpid(), getppid());
                }
                else {
                        sleep(0.10);
                        printf("Fin du proccessus père [%d]\n", getpid());
                }
        }

        return(EXIT_SUCCESS);
}

