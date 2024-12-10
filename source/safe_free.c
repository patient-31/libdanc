/*
 * ________________________________________________________________________________
 * |  File: safe_free.c
 * |  Project: source
 * |  File Created: Wednesday, 11th December 2024 07:05 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/libdanc.h"

void safe_free(void *tofree)
{
	if (tofree)
		free(tofree);
}