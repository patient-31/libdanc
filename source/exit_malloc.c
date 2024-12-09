/*
 * ________________________________________________________________________________
 * |  File: exit_malloc.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 02:32 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/libdanc.h"

void *exit_malloc(size_t size, t_program *c, char *mess) 
{
	void *ptr = malloc(size);
	if (!ptr) {
		ERROR_MEM(c, mess); // cleans up
    }
    return ptr;
}