/*
 * ________________________________________________________________________________
 * |  File: split.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 07:15 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/libdanc.h"

char	**split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s)
		return (0);
	k = wordcnt(s, c);
	split = safe_malloc(sizeof(char *) * (k + 1), "allocation for split() failed");
	if (!split)
		return (0);
	i = 0;
	j = 0;
	while (i < k)
	{
		while (s[j] == c)
			j++;
		s = &s[j];
		j = 0;
		while (s[j] != c && s[j])
			j++;
		split[i] = strndup(s, j);
		if (!split[i])
			save_to_error_txt("string allocation failed, split[i]");
		i++;
	}
	split[i] = 0;
	return (split);
}
