#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>

#define SIZE 30
#define LOG_TIME  	0x01 //00000001
#define LOG_DATE  	0x02 //00000010
#define LOG_USER  	0x04 //00000100
#define LOG_COUNT 	0x08 //00001000
#define LOG_ALL      0xff //11111111
#define LOG_FULLTIME 0x03 //00000011

void logmsg(FILE*,char*,uint8_t);
int main(){
	
	logmsg(stdout, "something", LOG_USER|LOG_FULLTIME /*==LOG_ALL*/ );
}

void logmsg(FILE *fp, char *str, uint8_t option){
	static long logcount = 0;
	time_t tmp = time(0);
	struct tm *tms = localtime(&tmp);
	char time[SIZE];
	char date[SIZE];

	strftime(time, SIZE, "%H:%M:%S", tms);
	strftime(date, SIZE, "%F (%a)", tms);

	if (option & LOG_COUNT) fprintf(fp, "log_count:\t%li\n", ++logcount);
	if (option & LOG_DATE) fprintf(fp, "date:\t%s\n", date);
	if (option & LOG_TIME) fprintf(fp, "time:\t%s\n", time);
	if (option & LOG_USER) fprintf(fp, "user:\t%s\n", getlogin());

	printf("%s\n",str);
}

