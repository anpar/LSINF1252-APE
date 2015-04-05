#include <stdio.h>
#include <stdlib.h>
 
int main(int argc, const char *argv[]) 
{
	if(argc > 1) 
	{
		int a; 
		for(int i = 1; i < argc; i++) {
			a = atoi(argv[i]); 
			printf("%d\n", a);
		} 
	}
	else
	{
		return(EXIT_FAILURE);
	}
}
