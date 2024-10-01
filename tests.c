#include <stdio.h>
#include <stdlib.h>
#include "includes.c"

void main()
{
    Word cont_1 = 15;

    Word cont_2 = read_field(15, 1, 3);
    printf("%d\n", cont_2);
}
