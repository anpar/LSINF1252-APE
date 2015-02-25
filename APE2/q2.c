#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Invalid numbers of arguments.\n");
	}
	else
	{
		lwbit(atoi(argv[1]));
	}
}

lwbit(int i)
{
	return(i&(~i+1));	
}
