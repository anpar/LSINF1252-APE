#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	char *ptr = "Test";
	int i = 0;
	while (*(ptr+i) != '\0')
	{
		printf("L'adresse %p contient %c.\n", ptr+i,*(ptr+i));
		i++;
	}
}

