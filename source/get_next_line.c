/*
 * ________________________________________________________________________________
 * |  File: get_next_line.c
 * |  Project: source
 * |  File Created: Monday, 9th December 2024 04:00 pm
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "../includes/libdanc.h"

char *get_next_line(int fd)
{
	int i;
	char *line;
	int buffer_mult = 1;
	line = safe_malloc(BUFFER_SIZE);

	i = 0;
	while (1)
	{
		if (i == BUFFER_SIZE * buffer_mult)
		{
			buffer_mult += 1;
			line = realloc(line, BUFFER_SIZE * buffer_mult);
			if (!line)
			{
				FILE *err = fopen("error.txt", "a");
				fprintf(err, "get_next_line allocation\n");
				fclose(err);
				return NULL;
			}
		}
		int byte_read = read(fd, &line[i], 1);
		if (byte_read == 0)
		{
			line[i] = '\0';
			return line;
		} 
		else if (byte_read == -1)
		{
			free(line);
			FILE *err = fopen("error.txt", "a");
			fprintf(err, "get_next_line error from read function call\n");
			fclose(err);
			return NULL;
		}
		if (line[i] == '\n' || line[i] == '\0')
		{
			line[i] = '\0';
			return line;
		}
		i += 1;	
	}
}