#include <stdlib.h>
#include <stdio.h>
#include "list.h"

#include "print_malloc.h"

struct chunk {
	struct chunk* next;
	void* ptr;
	size_t size;
};

struct chunk* head;

static size_t total_alloc = 0;
void *print_calloc(size_t nmemb, size_t size) {
	void* ptr;
	printf("allocating %d bytes, already %d allocated\n", nmemb*size, total_alloc);
	total_alloc += nmemb * size;
	ptr = calloc(nmemb, size);

	if (!ptr) {
		puts("failed");
		total_alloc -= nmemb * size;
		return NULL;
	}

	printf("\tallocated to %p\n", ptr);

	struct chunk* elem = simple_list_add_before(&head, ptr);
	if (elem) {
		elem->ptr = ptr;
		elem->size = nmemb * size;
	} else {
		free(ptr);
		total_alloc -= nmemb * size;
		ptr = NULL;
		puts("\tfailed to allocate list entry");
	}

	return ptr;
}

void print_free(void* ptr) {
	struct chunk* elem = simple_list_find(head, ptr);

	free(ptr);
	if (elem) {
		total_alloc -= elem->size;
		printf("free %d bytes at %p, %d allocated\n", elem->size, ptr, total_alloc);
		simple_list_remove(&head, elem);
	} else
		printf("free (unknown) bytes at %p\n", ptr);
}

void *print_malloc(size_t size) {
	return print_calloc(1, size);
}

void *print_realloc(void *ptr, size_t size) {
	printf("XXX realloc %p to %d bytes\n", ptr, size);
	if (!ptr) {
		printf("\tallocating %d bytes, already %d allocated\n", size, total_alloc);
		total_alloc += size;
	}
	return realloc(ptr, size);
}
