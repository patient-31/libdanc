/*
 * ________________________________________________________________________________
 * |  File: test.c
 * |  Project: libdanc
 * |  File Created: Friday, 13th December 2024 10:08 am
 * |  Author: Daniel Haddington [haddingtondaniel5@icloud.com]
 */

#include "includes/libdanc.h"


int main() {
	
	srand(time(NULL));
	printf("Random Integer: %d\n", rand_range(0, 50));
    return 0;
}