#include <stdio.h>
#include <stdlib.h>
#include "mm.h"

/* Return usec */
double comp_time(struct timeval time_s, struct timeval time_e) {

  double elap = 0.0;

  if (time_e.tv_sec > time_s.tv_sec) {
    elap += (time_e.tv_sec - time_s.tv_sec - 1) * 1000000.0;
    elap += time_e.tv_usec + (1000000 - time_s.tv_usec);
  }
  else {
    elap = time_e.tv_usec - time_s.tv_usec;
  }
  return elap;
}

//generate linked list
int mm_generate_list(mm_t *mm)
{
    mm_chunk *previous_chunk = NULL;
    
    for(int i = 0; i <= mm->how_many_chunks; i++)
    {
        mm_chunk *chunk = NULL;
        
        chunk = (mm_chunk*)malloc(sizeof(mm_chunk));
        if (chunk == NULL)
        {
            //return error if chunk init DNE
            return -1;
        }
        
        chunk->addr = mm->mem + (i+mm->chunk_size);
        chunk->next_chunk = NULL;
        chunk->status = FREE_BLOCK;
    
        if (previous_chunk != NULL)
        {
            previous_chunk->next_chunk = (void*) chunk;
            chunk->prev_chunk = (void*) previous_chunk;
        }
        
        if (i == 0)
        {
            mm->head_chunk = (void*)chunk;
        }
        
        previous_chunk = chunk;
        mm->tail_chunk = (void*)chunk;
    }
    return 0;
}

/* TODO - Implement.  Return 0 for success, or -1 and set errno on fail. */
int mm_init(mm_t *mm, int hm, int sz)
{
    //hm is how many chunks
    //sz is size of each chunk
    if(mm ==  NULL|| hm <= 0 || sz<=0)
    {
        //return error if there are 0 or less blocks
        //OR size of each block is 0 or negative
        //OR mm DNE
        return -1;
    }
    
    mm->chunk_size = sz;
    mm->how_many_chunks = hm;
    mm->num_chunks_free = hm;//all should be free at initialization
    mm->total_mem_size = sz*hm;//Total Size = num of chunks * size of chunks
    mm->head_chunk = NULL;
    mm->tail_chunk = NULL;
    
    mm->mem = (void *)malloc(mm->total_mem_size);

    if(mm->mem == NULL)
    {
        return -1;
    }
    
    mm_generate_list(mm);
    
  return 0;  /* TODO - return the right value */
}

/* TODO - Implement */
void *mm_get(mm_t *mm)
{

}

mm_chunk *read_list(mm_t *mm, void *chunk)
{
    //implementation of linear search algorithm
    mm_chunk * current_chunk = (void*) mm->tail_chunk;
    //cycle through the doubly linked list
    while (current_chunk->prev_chunk != NULL)
    {
        if (current_chunk->addr == chunk)
        {
            return current_chunk;
        }
        current_chunk = (void*) current_chunk->prev_chunk;
    }
    return NULL;
}

/* TODO - Implement */
void mm_put(mm_t *mm, void *chunk)
{

}


/* TODO - Implement */
void mm_release(mm_t *mm)
{
    //clear mm struct values
    mm->mem = NULL;
    mm->chunk_size = 0;
    mm->how_many_chunks = 0;
    mm->total_mem_size = 0;
    mm->num_chunks_free = 0;
    
    //clear doubly linked list
    mm_chunk * head_ptr = (void*)mm->head_chunk;
    while (head_ptr != NULL)
    {
        mm->head_chunk = head_ptr->next_chunk;
        free(head_ptr);
        head_ptr = (void*) mm->head_chunk;
    }
}


/*
 * TODO - This is just an example of how to use the timer.  Notice that
 * this function is not included in mm_public.h, and it is defined as static,
 * so you cannot call it from other files.  Instead, just follow this model
 * and implement your own timing code where you need it.
 */
static void timer_example() {
  struct timeval time_s, time_e;

  /* start timer */
  gettimeofday (&time_s, NULL);

  /* TODO - code you wish to time goes here */

  gettimeofday(&time_e, NULL);

  fprintf(stderr, "Time taken = %f msec\n",
          comp_time(time_s, time_e) / 1000.0);
}
