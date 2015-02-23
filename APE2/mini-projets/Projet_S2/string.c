#include <stdio.h>
#include <stdlib.h>
// Avoid warning message 'implicit declaration of function...'
#include <ctype.h>
#include <string.h>

size_t strlen(const char *s) {
	int i = 0;
	while(*(s+i) != '\0') {
		i++;
	}
	return(i);
}

char *strcat(char *dest, const char *src) {
	size_t dest_len = strlen(dest);
	int i = 0;
	while(*(src+i) != '\0') {
		dest[dest_len+i] = src[i];
		i++;
	}
	return(dest);
}

char *tolowerstr(const char *str) {
	int i;
	size_t len = strlen(str);
	char *ptr = (char *) malloc(sizeof(char)*(len+1));
	if (ptr != NULL) {
		for (i = 0; i < len; i++) {
			*(ptr+i) = tolower(*(str+i));
		}
	}
	return(ptr);
}

int strcasecmp(const char *s1, const char *s2) {
	return(strcmp(tolowerstr(s1), tolowerstr(s2)));
}

int main (int argc, const char *argv[]) {
	// Tests
	char foo[] = "foo";
	printf("The length of foo is %zu.\n", strlen(foo));
	const char bar[] = "bar";
	printf("The concatenation of foo and bar gives : %s.\n", strcat(foo,bar));
	const char str[] = "FooBar";
	printf("tolowerstr(FooBar) returns %s.\n", tolowerstr(str));
	const char str1[] = "Tintin";
	const char str2[] = "tinTin";
	printf("strcasecmp(str1,str2) returns %d.\n", strcasecmp(str1,str2));
	return(EXIT_SUCCESS);
}

