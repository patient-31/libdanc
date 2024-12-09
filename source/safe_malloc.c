/*
 * ________________________________________________________________________________
 * |  File: safe_malloc.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 02:19 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/libdanc.h"

void *safe_malloc(size_t size) 
{
	void *ptr = malloc(size);
	if (!ptr) {
		FILE *err = fopen("error.txt", "a");
		if (err) {
			fprintf(err, "Error: Memory allocation failed for size %zu\n", size);
			fclose(err);
		} else {
			fprintf(stderr, "Error: Memory allocation failed for size %zu\n", size);
		}
        return NULL;
    }
    return ptr;
}