/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** calloc.c
*/

#include "libmy_malloc.h"

size_t highest_pow_2(size_t x)
{
    size_t i = 0, p = 1;
    if (x <= p)
        return (2);
    while (x > p)
        p *= 2;
    return (p);
}

void duplicate_mem_block(mb_t *src , mb_t *dst)
{
    int *sdata, *ddata;
    size_t i;
    sdata = (int *) (src+1);
    ddata = (int *) (dst+1);
    for (i = 0; (i*4) < src->size && (i*4) < dst->size; i++)
        ddata[i] = sdata[i];
}

void *calloc(size_t nmemb, size_t size)
{
    size_t total = nmemb*size;
    if (size != total / nmemb) return (NULL);
    if (!total) return (NULL);
    void *ptr = malloc(total);
    if (!ptr) return (NULL);
    for (size_t i = 0; i < nmemb; i++)
        *((char *)ptr+i) = 0;
    return ptr;
}

void *realloc(void *ptr, size_t size)
{
    if (!ptr || !size) return (malloc(size));
    mb_t *mem_block = (mb_t *) (ptr - BLOCK_SIZE);
    if (size <= mem_block->size) return (ptr);
    void *new_block = malloc(size);
    if (new_block) {
        duplicate_mem_block(mem_block, new_block - BLOCK_SIZE);
        free(ptr);
    }
    return (new_block);
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    size_t total = nmemb*size;
    if (size != total / nmemb) return (NULL);
    return (realloc(ptr, total));
}