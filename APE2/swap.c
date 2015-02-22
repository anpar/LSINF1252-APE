#include <stdio.h>
#include <stdlib.h>
struct fract_t {
	int num;
	int denum;
};

void swap(struct fract_t *a, struct fract_t *b) {
        int temp1 = a->num;
        int temp2 = a->denum;
        a->num = b->num;
        a->denum = b->denum;
        b->num = temp1;
        b->denum = temp2;
}


int main(int argc, char *argv[]) {
	struct fract_t demi = {1,2};
	struct fract_t *demi_ptr = &(demi);
	struct fract_t tiers = {1,3};
	struct fract_t *tiers_ptr = &(tiers);
	printf("demi = %d/%d.\ntiers = %d/%d.\n", demi.num, demi.denum, tiers.num, tiers.denum);
	swap(demi_ptr, tiers_ptr);
	printf("demi = %d/%d.\ntiers = %d/%d.\n", demi.num, demi.denum, tiers.num, tiers.denum);
}
