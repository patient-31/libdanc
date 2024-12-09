/*
 * ________________________________________________________________________________
 * |  File: free_2d_char.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 07:36 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/libdanc.h"

void	free_2d_char(char **f, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (f[i])
			free(f[i++]);		
	}
	if (f)
		free(f);
}