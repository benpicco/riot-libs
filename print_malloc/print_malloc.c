#include <stdlib.h>
#include <stdio.h>

#include "print_malloc.h"

static size_t total_alloc = 0;
void *print_calloc(size_t nmemb, size_t size) {
	void* ptr;
	printf("allocating %d bytes, already %d allocated\n", nmemb*size, total_alloc);
	total_alloc += nmemb * size;
	ptr = calloc(nmemb, size);
	printf("\tallocated to 0x%x\n", ptr);
	return ptr;
}

void *print_malloc(size_t size) {
	return print_calloc(1, size);
}

void *print_realloc(void *ptr, size_t size) {
	printf("realloc 0x%x to %d bytes\n", ptr, size);
	if (!ptr) {
		printf("\tallocating %d bytes, already %d allocated\n", size, total_alloc);
		total_alloc += size;
	}
	return realloc(ptr, size);
}