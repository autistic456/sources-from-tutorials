#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(int argc, char **argv){
	if (argc < 3){
		fprintf(stderr, "usage: %s <library> <number>\n", argv[0]);
		exit(1);
	}
	char *lname = argv[1];
	int num = atoi(argv[2]);
	void *handle = dlopen(lname, RTLD_LAZY);
	if(!handle)
		fprintf(stderr, "dlopen: %s\n", dlerror());

	int (*op)(int);
	op=dlsym(handle, "op");
	char *(*getName)() = dlsym(handle, "getName");
	printf("%s\n",getName());
	printf("%i --> %i\n",num,op(num));
	
	dlclose(handle);
}
