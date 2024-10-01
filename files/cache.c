#include <stdlib.h>
#include "typedefs.c"

build_cache(Cache cache, int words_per_line, int lines_per_set, int sets_per_cache)
{
    int words_remaining;
    int lines_remaining;
    int sets_remaining;

    cache.sets = (Cache_set*) malloc(sets_per_cache * sizeof(Cache_set));

    for(sets_remaining = sets_per_cache - 1; sets_remaining >= 0; sets_remaining--)
    {
        Cache_set set;
        set.lines = (Cache_line*) malloc(lines_per_set * sizeof(Cache_line));

        for(lines_remaining = lines_per_set - 1; lines_remaining >= 0; lines_remaining--)
        {
            Cache_line line;
            line.words = (Word*) malloc(words_per_line * sizeof(Word));

            for(words_remaining = words_per_line - 1; words_remaining >= 0; words_remaining--)
            {
                line.words[words_remaining] = 0;
            }
            set.lines[lines_remaining] = line;
        }
        cache.sets[sets_remaining] = set;
    }
}
