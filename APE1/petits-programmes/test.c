#include <stdlib.h>
#include <stdio.h>
/*
	Subset of the Unix 'test' command.
	Antoine PARIS - 17/02/2015
*/
int main (int argc, const char *argv[])
{
	if (argc != 4)
	{
		fprintf(stderr, "Invalid numbers of arguments.\n");
		return(2);
	}
	else
	{	
		// Convert arguments
		int arg1 = atoi(argv[1]);
		int arg3 = atoi(argv[3]);			
		if (strcmp(argv[2],"-eq") == 0)
		{
			eq(arg1,arg3);
		}
		else if (strcmp(argv[2], "-ge") == 0)
		{
			ge(arg1,arg3);
		}
		else if (strcmp(argv[2], "-gt") == 0)
		{
			gt(arg1,arg3);
		} 
		else if (strcmp(argv[2], "-le") == 0)
		{
			le(arg1,arg3);
		}
		else if (strcmp(argv[2], "-lt") == 0)
		{
			lt(arg1,arg3);
		}
		else if (strcmp(argv[2], "-ne") == 0)
		{
			ne(arg1,arg3);
		}
		else
		{
			fprintf(stderr, "Invalid expression.\n");
			return(3);
		}
	}
}

int eq(int a, int b)
{
	return(!(a == b));
}
int ge(int a, int b)
{	
	return(!(a >= b));
}

int gt(int a, int b)
{
	return(!(a > b));
}
int le(int a, int b)
{
	return(!(a <= b));
}
int lt(int a, int b)
{
	return(!(a < b));
}
int ne(int a, int b)
{
	return(!(a != b));
}
