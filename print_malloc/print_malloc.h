#ifndef PRINT_MALLOC_H_
#define PRINT_MALLOC_H_

void *print_malloc(size_t size);
void *print_calloc(size_t nmemb, size_t size);
void *print_realloc(void *ptr, size_t size);

#endif