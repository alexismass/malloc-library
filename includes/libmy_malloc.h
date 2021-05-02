/*
** EPITECH PROJECT, 2021
** malloc
** File description:
** malloc.c
*/

#ifndef __LIBMY_MALLOC_H__
#define __LIBMY_MALLOC_H__

#include <stdlib.h>
#include <unistd.h>
#define PAGE_SIZE 4096
#define BLOCK_SIZE 32

typedef enum block_status
{
    FREE,
    BUSY
}bs_t;

typedef struct memory_block
{
    size_t size;
    bs_t status;
    struct memory_block *next;
}mb_t;

size_t highest_pow_2(size_t x);
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb , size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif