//  main_mm.c
//


#include <stdio.h>
#include <stdlib.h>
#include "mm.h"

int main()
{
    mm_t test_mm;
    void* test[NUM_CHUNKS];
    
    //given timer initialization
    struct timeval time_s, time_e;
    
    int init_error_test = mm_init(&test_mm, NUM_CHUNKS, CHUNK_SIZE);
    if(init_error_test == -1)
    {
        fprintf(stderr, "%s\n", "MM init failed");
        return 1;
    }
    
    /* start timer */
    gettimeofday (&time_s, NULL);
    
    /* TODO - code you wish to time goes here */
    //mem_get memory allocation
    for (int i = 0; i<NUM_CHUNKS; i++)
    {
        test[i] = mm_get(&test_mm);
    }
    
    //mm put memory deallocation
    for (int j = NUM_CHUNKS-1; j>=0; j--)
    {
        mm_put(&test_mm, test[j]);
    }
    
    gettimeofday(&time_e, NULL);
    
    fprintf(stderr, "Time taken for MM_test = %f msec\n",
            comp_time(time_s, time_e) / 1000.0);
    
    mm_release(&test_mm);
    
    return 0;
    
}
