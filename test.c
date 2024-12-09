/*
 * ________________________________________________________________________________
 * |  File: test.c
 * |  Project: danclib
 * |  File Created: Monday, 9th December 2024 06:26 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "includes/libdanc.h"

#define TM_FREQ_64      mask(0)      // 0th bit set
#define TM_FREQ_1024    mask(1, 0)   // 0th and 1st bits set

struct t_program {
	char *some_data;
};

void cleanup(t_program *c)
{
	free(c);
}

int main()
{
	t_program *c;
	c = malloc(sizeof(t_program));

	int fd = open("newfile", O_RDONLY);
	char *string =  get_next_line(fd);
	printf("%s", string);
    return 0;
}