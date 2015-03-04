#include <stdlib.h>
#include <stdio.h>

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

int main(int argc, char *argv[]) meofday(&tv, NULL);
        start = tv.tv_usec;
        good_init();
        gettimeofday(&tv, NULL);
        end = tv.tv_usec;
        printf("good_init takes %d micro-seconds.\n",(int) end-start);
        gettimeofday(&tv, NULL);
        start = tv.tv_usec;
        bad_init();
        gettimeofday(&tv, NULL);
        end = tv.tv_usec;
        printf("bad_init takes %d micro-seconds.\n",(int) end-start);
        return(EXIT_SUCCESS);		
}
