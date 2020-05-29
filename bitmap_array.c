#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define set_bit(BF,N) BF |= \
	((uint64_t)1 << N)

#define clr_bit(BF,N) BF &= \
	~((uint64_t)0x0000000000000001 << N)
	
#define is_bit_set(BF,N) ((BF >> N) & 0x1)

uint64_t ar = 0;
int main (void) {
	
	set_bit(ar, 0);
	set_bit(ar, 2);
	set_bit(ar, 9);
	set_bit(ar, 7);
	set_bit(ar, 45);

	clr_bit(ar,7);
	for(int i =0; i<64 ; i++)
	{
		if(is_bit_set(ar,i))
			printf("+");
		else
			printf("-");
	}
	printf("\n");

	return 0;
}

