/*
 * ________________________________________________________________________________
 * |  File: tabdup.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 07:23 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/libdanc.h"

char	**tabdup(char **in)
{
	size_t	i;
	char	**out;

	i = 0;
	out = malloc(sizeof(char *) * (lstlen(in) + 1));
	if (!out)
		return (NULL);
	while (in[i])
	{
		out[i] = strdup(in[i]);
		i++;
	}
	out[i] = NULL;
	return (out);
}
