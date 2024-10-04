#include <stdlib.h>
#include "typedefs.c"

void build_cache(Cache* cache, int words_per_line, int lines_per_set, int sets_per_cache)
{
    int sets_remaining;

    cache->sets = (Cache_set*) malloc(sets_per_cache * sizeof(Cache_set));

    for(sets_remaining = sets_per_cache - 1; sets_remaining >= 0; sets_remaining--)
    {
        Cache_set* set;
        build_set(set, lines_per_set, words_per_line);
        cache->sets[sets_remaining] = set;
    }
}

void build_set(Cache_set* set, int lines_per_set, int words_per_line)
{
    int lines_remaining;
    
    set->lines = (Cache_line*) malloc(lines_per_set * sizeof(Cache_line));

    for(lines_remaining = lines_per_set - 1; lines_remaining >= 0; lines_remaining--)
    {
        Cache_line* line;
        build_line(line, words_per_line);
        set->lines[lines_remaining] = line;
    }
}

void build_line(Cache_line* line, int words_per_line)
{
    int words_remaining;
    
    line->words = (Word*) malloc(words_per_line * sizeof(Word));

    for(words_remaining = words_per_line - 1; words_remaining >= 0; words_remaining--)
    {
        line->words[words_remaining] = 0;
    }
}