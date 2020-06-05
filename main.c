#include <stdio.h>
#include <stdlib.h>
#include "libraryExample.h"

int main(int argc, char **argv){
	if(argc){
		printf("%s\n",argv[1]);
		printf("%s\n",reverse(argv[1]));
	}
}
