#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>

/*
 * L'idée ici est de créer un très grand tableau
 * à deux dimensions initialement nul. Dans un premier temps,
 * on va initialiser ce tableau ligne par ligne (et donc 
 * profiter de la localité spatiale). On va ensuite l'initialiser
 * colonne par colonne (et donc plus du tout profiter de la
 * localité spatialei).
 *
 * Résultat :
 * good_init (line by line) takes 302179 micro-seconds.
 * bad_init (row by row) takes 991787 micro-seconds.
 *
 * Conclusion : bad_init prend 3 fois plus de temps =>
 * la localité spatiale n'est pas un mythe.
 */

#define ROWS 10000
#define COLS 10000

int **array;
struct timeval tvStart, tvEnd;

void good_init() {
        for(int i=0; i<ROWS; i++) {
                for(int j=0; j<COLS; j++) {
                        array[i][j] = 1252;
                }
        }
}
	
void bad_init() {
        for(int i=0; i<COLS; i++) {
                for(int j=0; j<ROWS; j++) {
                        array[j][i] = 1225;
                }
        }
}

long timeval_diff(struct timeval *t2, struct timeval *t1) 
{ 
        long diff = (t2->tv_usec + 1000000 * t2->tv_sec) - (t1->tv_usec + 1000000 * t1->tv_sec);
        return (diff); 
}

int main(int argc, char *argv[]) 
{
	// Initialize array
        array = (int **) malloc(ROWS*sizeof(int *));
        if(array == NULL)
                return(EXIT_FAILURE);

        for(int i=0; i<ROWS; i++) {
                array[i] = (int *) malloc(COLS * sizeof(int));
                if(array[i] == NULL)
                        return(EXIT_FAILURE);
        }
        
        int err;

        err=gettimeofday(&tvStart, NULL);
        if(err!=0)
                return(EXIT_FAILURE);

	good_init();
        err=gettimeofday(&tvEnd, NULL);
        if(err!=0)
                return(EXIT_FAILURE);

	printf("good_init (line by line) takes %ld micro-seconds.\n", timeval_diff(&tvEnd, &tvStart));
	
        err=gettimeofday(&tvStart, NULL);
        if(err!=0)
                return(EXIT_FAILURE);

	bad_init();
	err=gettimeofday(&tvEnd, NULL);
        if(err!=0)
                return(EXIT_FAILURE);

	printf("bad_init (row by row) takes %ld micro-seconds.\n", timeval_diff(&tvEnd, &tvStart));

        // Free array
        for(int i=0; i<ROWS; i++) {
                free(array[i]);
        }
        free(array);

        return(EXIT_SUCCESS);
}
