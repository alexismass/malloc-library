# Unix System Programming - Malloc

**Unauthorized Functions**: `mmap`, `munmap`, `*alloc`, `free`, `dlopen`, `dlsym`.<br><br>
Using only **brk**/**sbrk** and your amazing mind, rewrite the 5 following **C library** functions: `malloc`, `calloc`, `realloc`, `reallocarray` and `free`.
Your function prototypes must be the same as the ones from the **C library**, and must be contained in the shared library compiled by your **Makefile**.
```
void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb , size_t size);
void *realloc(void *ptr, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);
```

## Allocation Strategie
You allocation strategy must be like follow:
- you must align your memory on a **power of 2**.
- the break must always be **aligned** on a **multiple of 2** pages.
- you must implement the **best fit** algorithm.

## Results
| Test Name           | Note     |
|---------------------|----------|
| Basics Tests:       | **100%** |
| Intermediate Tests: | **95%**  |
| Hard Tests:         | **95%**  |
| Bestfit Tests:      | **100%** |
| Exec Tests:         | **100%** |
