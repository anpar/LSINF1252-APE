#include <stdio.h>
#include <stdlib.h>

/*
 * Pour cet exercice, on vous fourni une structure représentant une fraction
 * - Vous devez implémenter une fonction permettant de comparer 2 fractions
 *     (fraction_compare() : la signature vous est fournie).
 * - Vous devez ensuite implémenter une autre fonction qui utilisera qsort et
 *     votre fonction de comparaison pour trier un tableau de fraction_t par
 *     ordre croissant (fraction_sort() : signature fournie).
 * - Vous emploierez ensuite votre fonction fraction_sort() pour écrire une
 *     fonction qui trie un tableau de fraction_t en ignorant les 3 premiers
       et derniers éléments (fraction_sortIgnore3fl() : signature fournie).
 *
 * NB : même si des préconditions sont indiquées, il vaut mieux les vérifier.
 */

/* type représentant une fraction : */
typedef struct {
    int numerateur;
    int denominateur;
} fraction_t;


/*
 * Compare 2 fraction_t
 * Précondition : - les 2 paramètres sont des pointeurs sur des fraction_t valides (Non NULL donc)
 *                - aucun dénominateur ne vaut 0
 * Renvoie : < 0 si la première fraction est plus petite que la seconde
 *           > 0 si la première est plus grande
 *           0 si elles ont la même valeur
 */
int fraction_compare(const void *a, const void *b) {
    if(a == NULL || b == NULL)
        exit(EXIT_FAILURE);

    fraction_t *fraction_1 = (fraction_t *) a;
    fraction_t *fraction_2 = (fraction_t *) b;

    if(fraction_1->denominateur == 0 || fraction_2->denominateur == 0)
        exit(EXIT_FAILURE);

    double value_1 = ((double) fraction_1->numerateur) / ((double) fraction_1->denominateur);
    double value_2 = ((double) fraction_2->numerateur) / ((double) fraction_2->denominateur);

    double difference = value_1 - value_2;

    if(difference > 0) {
        return(1);
    }
    else if (difference < 0) {
        return(-1);
    }
    else {
        return(0);
    }
}

/*
 * Trie un tableau de fraction_t par ordre croissant
 * Params : - tab est un pointeur vers le permier élément d'un tableau de fraction_t
 *          - len indique le nombre d'éléments contenus dans le tableau
 * Précondition : - tab n'est pas NULL et pointe vers un tableau valide
 *                - len <= à la longueur réelle du tableau
 * Postcondition : tab a été trié par qsort dans l'ordre croissant sur la longueur indiquée
 *                  par len.
 */
void fraction_sort(fraction_t * tab, size_t len) {
    if(tab == NULL)
        exit(EXIT_FAILURE);

    if(len <= 0)
        exit(EXIT_FAILURE);

    qsort((void *) tab, len, sizeof(fraction_t), *fraction_compare);
}

/*
 * Trie un tableau de fraction_t par ordre croissant en ignorant les 3 premiers et
 *   derniers éléments (en laissent ceux là dans l'ordre où ils se trouvent).
 * Params : - tab est un pointeur vers le permier élément d'un tableau de fraction_t
 *          - len indique le nombre d'éléments contenus dans le tableau
 * Précondition : - tab n'est pas NULL et pointe vers un tableau valide
 *                - len <= à la longueur réelle du tableau
 *                - len vaut au moins 6 (3+3)
 * Postcondition : tab a été trié par qsort dans l'ordre croissant sur la longueur indiquée
 *                  par len en ignorant les 3 premiers et derniers éléments.
 */
void fraction_sortIgnore3fl(fraction_t * tab, size_t len) {
    if(tab == NULL)
        exit(EXIT_FAILURE);

    if(len < 6)
        exit(EXIT_FAILURE);

    qsort((void *) (tab+3), len-6, sizeof(fraction_t), *fraction_compare);
}

int main(void) {
    /*
     * Test de fraction_compare
     */
    fraction_t frac_1 = {1,2};
    fraction_t frac_2 = {2,4};
    printf("fraction_compare returns %d.\n", fraction_compare((const void *) &frac_1, (const void *) &frac_2));

    return(EXIT_SUCCESS);
}
