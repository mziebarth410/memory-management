//  main_malloc.c
//
//

#include <stdio.h>
#include <stdlib.h>
#include "mm.h"

int main()
{
    void* test[NUM_CHUNKS];
    
    struct timeval time_s, time_e;
    
    /* start timer */
    gettimeofday (&time_s, NULL);
    
    /* TODO - code you wish to time goes here */
   
    //initial memory allocation
    for (int i = 0; i < NUM_CHUNKS; i++)
    {
        test[i] = (void*)malloc(CHUNK_SIZE);
        
    }
    
    //memory de allocation
    for (int j = NUM_CHUNKS-1; j>=0; j--)
    {
        free(test[j]);
    }
    
    gettimeofday(&time_e, NULL);
    
    fprintf(stderr, "Time taken for Malloc = %f msec\n",
            comp_time(time_s, time_e) / 1000.0);
    
    return 0;
}
