#include <stdlib.h>
#include <stdio.h>

int global;

void main(void)
{
        int local;
        int *ptr1 = (int *) malloc(sizeof(*ptr1));
        int *ptr2 = (int *) malloc(sizeof(*ptr2));

        printf("global %p loc %p p1 %p p2 %p\n", &global, &local, ptr1, ptr2); 
        /*
         * Executing multiple times this program gives:
         * global 0x60104c loc 0x7fffac20314c p1 0x1b6f010 p2 0x1b6f030
         * global 0x60104c loc 0x7fff0db22a4c p1 0x1ed6010 p2 0x1ed6030
         * global 0x60104c loc 0x7fffbb1a5c0c p1 0x1a35010 p2 0x1a35030
         * global 0x60104c loc 0x7fff984b546c p1 0x1e04010 p2 0x1e04030
         *
         * We observe that the global variable always stays at the same
         * place (in the uninitialized data segment).
         * The local variable is on the stack and seems to move randomly
         * between two executions.
         * p1 and p2 are of course on the stack. It seems that malloc
         * allocates a different number of bytes than requested. I was waiting
         * for something like:
         * p1 0x1b6f010 p2 0x1b6f018 (since type int * needs 8 bytes)
         * but here there is 32 bytes between p1 and p2. This thread
         * explains why : http://stackoverflow.com/questions/430163/why-does-malloc-allocate-a-different-number-of-bytes-than-requested
         * - First, Malloc makes no guarantees that two successive malloc calls return successive pointers.
         * - Second, depending on your specific architecture, different alignment rules apply; 
         * sometimes you might ask for a single byte, but the architecture prefers allocations on 8- or 4-byte intervals.
         * - Third, malloc needs some overhead to store how big the allocated block is, etc.
         *
         * We can also see that between two execution, addresses of p1 and p2
         * change (more or less randomly?). I think it's logical because
         * we don't free p1 and p2. Let's see what happen when we free
         * p1 and p2: nothing change. Malloc seems to allocate at random places on the heap.
         */
}
