#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main(void)
{
	printf("int : %zu bytes.\n",sizeof(int));
	printf("long : %zu bytes.\n", sizeof(long));
	printf("void * : %zu bytes.\n", sizeof(void *));
	printf("char * : %zu bytes.\n",sizeof(char *));
	printf("size_t : %zu bytes.\n",sizeof(size_t));
	printf("uint64_t : %zu bytes.\n",sizeof(uint64_t));
}
