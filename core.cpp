#include "core.h"

void qsort (void* base, int num, int size, int (*compare) (const void*, const void*));

int str_in_f (FILE* stream)
{
    char sym = '\0';
    int i = 0;

    while ((sym = getc (stream)) != EOF)
    {
        //i++;
        if (sym != '\n')
        {
            i++;
            while ((sym = getc (stream)) != '\n');
            //printf ("%d\n", i);
        }
    }

    return i;
}

char getstring (FILE* stream, char** str, int n)
{
    *str = (char*) calloc (n, sizeof(**str));

    char sym = '\0';

    int i = 0;

    while ((i < n) && ((sym = getc (stream)) != '\n'))
    {
        (*str)[i] = sym;
        i++;
        //printf ("!%d %c\n", i, (*str)[i]);
    }

    (*str)[i] = '\n';

    if (i > 0)
    {
        (*str)[i] = '\0';
    }

    return (*str)[0];
}
