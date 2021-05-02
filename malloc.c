/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc.c
*/

#include "libmy_malloc.h"
mb_t *heap = NULL;

int add_mem_block(size_t size)
{
    size_t page_size = PAGE_SIZE*2;
    size_t data_size = highest_pow_2(size) + BLOCK_SIZE;
    while (page_size < data_size)
        page_size *= 2;
    void *new_block = sbrk(page_size);
    if (new_block == (void *) -1)
        return 1;
    mb_t *new = new_block;
    new->size = data_size;
    new->status = BUSY;
    new->next = NULL;
    if (!heap) {
        heap = new;
        return (0);
    }
    new->next = heap;
    heap = new;
    return (0);
}

mb_t *retreive_free_mem_block(size_t size)
{
    if (!heap)
        return NULL;
    size_t data_size = highest_pow_2(size) + BLOCK_SIZE;
    mb_t *tmp = heap;
    while (tmp) {
        if (tmp->size >= data_size && tmp->status == FREE)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

void *malloc(size_t size)
{
    if (!size) return (NULL);
    mb_t *free = retreive_free_mem_block(size);
    if (!free) {
        if (add_mem_block(size)) return (NULL);
        return (void *) heap + BLOCK_SIZE;
    } else {
        free->status = BUSY;
        return (void *) free + BLOCK_SIZE;
    }
}

void free(void *ptr)
{
    if (!ptr)
        return;
    size_t page_size = PAGE_SIZE*2;
    void *end = sbrk(0);
    mb_t *mem_block = (mb_t *) (ptr - BLOCK_SIZE);
    while (mem_block->size > page_size)
        page_size *= 2;
    if (end == (ptr + (page_size-BLOCK_SIZE))) {
        heap = heap->next;
        sbrk(0-page_size);
        return;
    }
    mem_block->status = FREE;
    for (size_t i = 0; i < mem_block->size; i++)
        *((char *)ptr+i) = 0;
    return;
}