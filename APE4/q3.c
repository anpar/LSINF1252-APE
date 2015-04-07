#include <stdlib.h>
#include <stdio.h>

/*
 * Même sans utiliser gettimeofday(), on peut voir
 * immédiatement que sum est plus rapide que sum2. On sait
 * en effet que les tableaux sont stockés dans la mémoire
 * ligne par ligne. En sachant cela et en connaissant le principe
 * de la localité spatiale on sait donc que sum sera plus
 * rapide que sum2 (la question 1 le prouve en initialisant
 * deux tableaux différement).
 */

#define SIZE 10000 

int matrix[SIZE][SIZE];

int sum() { 
	int sum=0; 
	for(int i=0;i<SIZE;i++) { 
		for(int j=0;j<SIZE;j++) { 
			sum+=matrix[i][j]; 
		} 
	} 
	
	return sum;
 } 

int sum2() { 
	int sum=0; 
	for(int i=0;i<SIZE;i++) { 
		for(int j=0;j<SIZE;j++) { 
			sum+=matrix[j][i];
		 } 
	} 
	return sum; 
}
