#include <stdio.h>
#include <stdlib.h>
#include "includes.c"

void main()
{
    Cont cont_1 = 15;

    Cont cont_2 = read_field(15, 1, 3);
    printf("%d\n", cont_2);
}
