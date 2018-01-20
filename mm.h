#ifndef __MM_H
#define __MM_H

#include <sys/time.h>

#define INTERVAL 0
#define INTERVAL_USEC 50000
#define CHUNK_SIZE 64
#define NUM_CHUNKS 1000000
#define FREE_BLOCK 1
#define USED_BLOCK 2

//Data Structure: Doubly Linked List
typedef struct{
    //reference address to linked list
    void *addr;
    //pointer to next mem block
    struct mm_chunk *next_chunk;
    //pointer to previous mem block
    struct mm_chunk *prev_chunk;
    //status of whether a chunk is used or free
    char status;
} mm_chunk;

/* TODO - Fill this in */
typedef struct {
    void *mem;
    int chunk_size;
    int how_many_chunks;
    int total_mem_size;
    int num_chunks_free;
    
    struct mm_chunk *head_chunk;
    struct mm_chunk *tail_chunk;
} mm_t;



/* TODO - Implement these in mm.c */
double comp_time(struct timeval time_s, struct timeval time_e);
int mm_generate_list(mm_t *mm);
int mm_init(mm_t *mm, int num_chunks, int chunk_size);
void *mm_get(mm_t *mm);
void mm_put(mm_t *mm, void *chunk);
void mm_release(mm_t *mm);

#endif
