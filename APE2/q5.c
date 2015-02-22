#include <stdlib.h>
#include <stdio.h>

struct foo_t {
	char a; // Needs 1 bytes	
	int b; // Needs 4 bytes (on a 64-bits machine)
};

int main(int argc, char *argv[]) {
	printf("foo_t needs %d bytes.\n", (int)  sizeof(struct foo_t));
	// Display 8. See data structure padding.
}
