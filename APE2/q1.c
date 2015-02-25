#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
int main(int argc, const char argv[])
{
	printf("int : %d bytes.\n",sizeof(int));
	printf("long : %d bytes.\n", sizeof(long));
	printf("void * : %d bytes.\n", sizeof(void *));
	printf("char * : %d bytes.\n",sizeof(char *));
	printf("size_t : %d bytes.\n",sizeof(size_t));
	printf("uint64_t : %d bytes.\n",sizeof(uint64_t));
}
