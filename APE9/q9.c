#include <stdlib.h>
#include <stdio.h>

int main(int argc, const char *argv[])
{
	if(argc != 2) {
		printf("Failure : no arguments.\n");
		return(EXIT_FAILURE);
	}
	
	printf("Success : result = %d.\n", 2*atoi(argv[1]));
	return(2*atoi(argv[1]));
}
