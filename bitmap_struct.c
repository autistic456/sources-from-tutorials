#include <stdio.h>
#include <stdlib.h>

struct counter_t {
	unsigned int little:2;
	unsigned int medium:4;
	unsigned int large:6;
} __attribute((packed));

int main (void) {
	
	struct counter_t c;	
	c.little=0;c.medium=0;c.large=0;	
	for(int i =0; i<10 ; i++)
	{
		printf("%u %u %u\n",
			c.little++, c.medium++, c.large++);
	}

	printf("sizof(struct counter)==%ld\n",sizeof(c));
	return 0;
}

