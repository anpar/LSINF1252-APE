#include <stdlib.h>
#include <stdio.h>

int *array;
long size = 100000;
struct timeval tv;
time_t start;
time_t end;

int main(int argc, char *argv[]) {
	gettimeofday(&tv, NULL);
	start = tv.tv_usec;
	good_init();
	gettimeofday(&tv, NULL);
	end = tv.tv_usec;
	printf("good_init takes %d micro-seconds.\n",(int) end-start);
	gettimeofday(&tv, NULL);
        start = tv.tv_usec;
	//bad_init();
	gettimeofday(&tv, NULL);
        end = tv.tv_usec;
	printf("bad_init takes %d micro-seconds.\n",(int) end-start);
	return(EXIT_SUCCESS);
}

int good_init() {
	array = (int *) malloc(size*sizeof(int));
	int i;
	for(i = 0; i < size; i++) {
		array[i] = 1252;
	}
	return(EXIT_SUCCESS);	
}
	
int bad_init() {
	array = (int *) malloc(size*sizeof(int *));
	int i;
	// A terminer, il faut parcourir le tableau sans le faire
	// avec un incrément de 1
	for(i = 0; i < size; i+) {
		array[i] = 1252;
	}
	return(EXIT_SUCCESS);
}
