#include "typedefs.c"

Word read_field(Word bin_instruction, int start, int end)
{
    int size = end - start;
    int mask = 0;

    while(size > 0)
    {
        mask <<= 1;
        mask++;
        
        size--;
    }

    mask <<= start;

    Word result = mask & bin_instruction;

    return (result >> start);
}