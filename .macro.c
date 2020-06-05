#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define check(x) ({int _val = (x); (_val ==-1? \
	({fprintf(stderr, "Error (" __FILE__ ":%d) -- " \
	"%s\n",__LINE__,strerror(errno)); \
	exit(-1);-1;}) : _val); })

int main (int argc, char **argv) {
	
	if (argc!=2){
		fprintf(stderr, "usage: %s <filename>\n", argv[0]);
		exit(-1);
	}
	
	int fd;
	fd=open(argv[1], O_RDONLY);
	
	if(fd<0){
		perror("open");
		fprintf(stderr,"errno = %s\n",strerror(errno));
		exit(-1);
	}
	
	for(char c;check(read(fd,&c,1))>0;)
		fputc(c,stdout);

	return 0;
}

