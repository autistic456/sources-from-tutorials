#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	char *des = malloc(7);
	for(char *src=argv[0], *p=des; (*p++=*src++); printf("%s\n",des));
}
