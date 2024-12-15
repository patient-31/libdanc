/*
 * ________________________________________________________________________________
 * |  File: test.c
 * |  Project: libdanc
 * |  File Created: Friday, 13th December 2024 10:08 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "includes/libdanc.h"
# include <fcntl.h>


int main(void)
{


	char **array;
	char *line10k;

	int i = 0;
	line10k = safe_malloc(sizeof(char) * (MAX_LINE_LENGTH + 6), "allocation line10k");
	while (i < MAX_LINE_LENGTH + 5)
	{
		line10k[i] = '0';
		i++;
	}
	write_string_to_file("long_line.txt", line10k);
	int fd = open("long_line.txt", O_RDONLY);
	array = get_file_2d(fd);

	print_2d_char(array);
	return (0);
}