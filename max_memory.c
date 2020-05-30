#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define GB (1<<30)
#define N 10000L //number of virtual blocks(arrays)

int main (void) {

    int *ar[N]; 
    for(int i =0; i<N ; i++)
    {
        ar[i]=malloc(GB); //alloc virtually one GB
        if(!ar[i]){
            printf("done at %i\n",i);
            return 0;
        }
    }
    printf("allocated %li blocks\n",N);

    for(int i =0; i<N ; i++)
    {
        memset(ar[i],2,GB); // get physical gigs for that array
        printf("wrote to %i GB\n",i+1);
    }


    return 0;
}
