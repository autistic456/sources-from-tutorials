#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <ctype.h>

int main (void) {
	
	int fd = open("./sometext.txt", O_RDWR);
	struct stat sb;
	
	if(fstat(fd,&sb)) perror("in function fstat"); 
	
	printf("file size is %ld bytes\n\n",sb.st_size);
	char* file_p = mmap(0, sb.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

	printf("printing file as an array of chars \n\n");
	for(int i =0; i<sb.st_size ; i++){
		if(!(i%2))
			file_p[i] = tolower(file_p[i]);
		if(file_p[i]=='5')
			file_p[i]='a';
		printf("%c", file_p[i]);
	}

	munmap(file_p, sb.st_size);
	close(fd);

	return 0;
}

