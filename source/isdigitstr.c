/*
 * ________________________________________________________________________________
 * |  File: isdigitstr.c
 * |  Project: source
 * |  File Created: Friday, 27th December 2024 03:57 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/libdanc.h"

bool isdigitstr(char *s)
{
	if (!s)
		return false;
	int i;

	i = 0;
	while (s[i] != NULL)
	{
		if (!isdigit(s[i]))
			return false;
		i++;
	}
	return true;
}