#include <pthread.h>
#include <semaphore.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define N 40                   // taille du buffer
static pthread_mutex_t mutex;  // mutex du buffer
static sem_t empty;            // si > 0 alors il y a des places libres dans le buffer
static sem_t full;             // si > 0 alors il y a des données dans le buffer

/*
 * Cette fonction initialise le mutex et les 2 sémaphores.
 * @Post : Le mutex et les sémaphores full et empty ont été
 * initialisés. Après l'initialisation, les sémaphores doivent
 * indiquer que le buffer est vide. (La capacité du buffer est
 * la constante N.)
 */
void init(void)
{
        pthread_mutex_init(&mutex, NULL);
        sem_init(&empty, 0, N);
        sem_init(&full, 0, 0);
}

/*
 * Producteur incomplet :
 * @Inv: - A chaque itération, le producer génère un entier et
 *         essaye de le mettre dans le buffer.
 *       - S'il n'y a plus de place dans le buffer, il attend 
 *         qu'il y en ait.
 *       - Quand il a mis un entier dans le buffer, il l'indique
 *         aux consommateurs.
 * 
 * A vous de compléter le code de cette fonction pour que l'invariant
 * soit respecté. Pensez aussi à protéger le buffer : n'oubliez pas 
 * qu'il est partagé entre tous les producteurs et consommateurs, mais
 * que les fonctions qui le manipulent (insert(), remove(), ...) 
 * ne sont pas thread-safe.
 */
void producer(int max) 
{
        int i;
        int item;
        for(i = 0; i < max; ++i) {
                item = produce(); // génère un entier
                sem_wait(&empty);
                pthread_mutex_lock(&mutex);
                insert(item); //  met l'entier généré dans le buffer 
                pthread_mutex_unlock(&mutex);
                sem_post(&full);
        }
}

