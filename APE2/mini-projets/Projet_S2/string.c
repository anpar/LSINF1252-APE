#include <stdio.h>
#include <stdlib.h>

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
	int i = 0;
	char newstr[strlen(str)];
	while(*(str+i) != '\0') {
		newstr[i] = tolower(str[i]);
		i++;
	}
	return(newstr);
}

int strcasecmp(const char *s1, const char *s2) {
	return(strcmp(tolowerstr(s1), tolowerstr(s2)));
}

void main (int argc, const char *argv[]) {
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
}
