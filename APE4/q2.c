#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

/*
 * On peut raisonnablement supposé que travailler
 * avec deux tableaux séparés sera plus rapide.
 * La localité spatiale implique que lorsque le processeur
 * veut accèder au byte A, les byte de A-X à A+X sont
 * chargés dans la mémoire cache également. Avec
 * la solution avec deux tableaux séparés, pas de problème.
 * Mais avec un tableau de structure, la totalité (ou une partie) des
 * bytes supplémentaires transférés en mémoire cache sera
 * utilisée pour stocker la chaine de caractère de
 * la structure, inutile pour le calcule de la somme
 *
 * Code pour lé vérifier. Gros draft, pas terminé.
 */

#define SIZE 100000

struct data {
        float f;
        char c[40];
};

struct data *array_heavy = malloc(SIZE*sizeof(struct data));

// Seconde méthode, un tableau contenant les floats
float *array_light = malloc(SIZE*sizeof(float));

void init() {
        // Initialisation du tableau de structure
        struct data item = {1.00, "lecoursdesystemeinformatiqueesttropcool"};
        
        for(int i=0; i<SIZE; i++) {
                array_heavy[i] = item;
                array_light[i] = 1.00;
        }

}

long long sum_heavy() {
        long long sum = 0;
        for(int i=0; i<SIZE; i++) {
                sum += (long long) (array_heavy[i]).f;
        }
        return(sum);
}
long long sum_light() {
        long long sum = 0;
        for(int i=0; i<SIZE; i++) {
                sum += (long long) array_light[i];
        }
        return(sum);
}

int main(void)
{
        printf("sum_light returns: %lld.\n", sum_light());
        printf("sum_heavy returns: %lld.\n", sum_heavy());

        return(EXIT_SUCCESS);
}
