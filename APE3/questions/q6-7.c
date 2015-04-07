#include <stdlib.h>
#include <stdio.h>

/*
 * -- Output without __attribute__((packed)) :
 * data (size: 24) points toward: 0x7fff13f23ce0.
 * data.c = a (char: 1) is stored at address: 0x7fff13f23ce0.
 * data.c use in fact 8 bytes.
 * data.l = 125212521252 (long: 8) is stored at address:0x7fff13f23ce8.
 * data.l use in fact 8 bytes.
 * data.s = 42 (short: 2) is stored at address: 0x7fff13f23cf0.
 * data.s use the remaining bytes.
 *
 * Size of data is 24 instead of 11 because of structure
 * padding (see: tackoverflow.com/questions/11770451/what-is-the-meaning-of-attribute-packed-aligned4)
 * -- Output with __attribute__((packed)) :
 * data (size: 11) points toward: 0x7fff7818ac00.
 * data.c = a (char: 1) is stored at address: 0x7fff7818ac00.
 * data.c use in fact 1 bytes.
 * data.l = 125212521252 (long: 8) is stored at address: 0x7fff7818ac01.
 * data.l use in fact 8 bytes.
 * data.s = 42 (short: 2) is stored at address: 0x7fff7818ac09.
 * data.s use the remaining bytes.
 *
 * CONCLUSION : __attribute_((packed)) avoid data padding.
 * But it's important to note that unaligned memory is slower.
 * We can also choose the size of the padding using
 * __attribute_((packed, aligned(X))) with X a power of 2.
 */

typedef struct __attribute__((packed)) {
        char c; // 1 bytes
        long l; // 8 bytes 
        short s; // 2 bytes 
} test_t;

int main(void)
{
        test_t data = {'a', 125212521252, 42};
        printf("data (size: %zu) points toward: %p.\n", sizeof(test_t), &data);
        printf("data.c = %c (char: %zu) is stored at address: %p.\n", data.c, sizeof(char), &(data.c));
        printf("data.c use in fact %ld bytes.\n", (void *) &(data.l) - (void *) &(data.c));
        printf("data.l = %ld (long: %zu) is stored at address: %p.\n", data.l, sizeof(long), &(data.l));
        printf("data.l use in fact %ld bytes.\n", (void *) &(data.s) - (void *) &(data.l));
        printf("data.s = %d (short: %zu) is stored at address: %p.\n", data.s, sizeof(short), &(data.s));
        printf("data.s use the remaining bytes.\n");
        return(EXIT_SUCCESS);
}
