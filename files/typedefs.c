typedef long Word;

typedef struct Cache_line
{
    Word* words;
} Cache_line;

typedef struct Cache_set
{
    Cache_line** lines;
} Cache_set;

typedef struct Cache
{
    Cache_set** sets;
    int substitution_index;
    int set_quantity;
} Cache;