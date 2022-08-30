#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//#include <TXLib.h>
#include <locale.h>

#include "core.h"

int main ()
{
    setlocale (LC_ALL, "ru_RU.CP866");

    FILE* InputFile = NULL;



    InputFile = fopen ("Onegin.txt", "r");
    assert (InputFile != NULL);


    char** PtrArr = NULL;

    int str_num = str_in_f (InputFile); //printf ("%d", str_num); return 0;
    fseek (InputFile, 0, SEEK_SET);

    PtrArr = (char**) calloc (str_num, sizeof (*PtrArr));
    assert (PtrArr != NULL);

    int i = 0;
    int sym_cnt = 0;
    char sym = '\0';

    //InputFile = fopen ("Onegin.txt", "r");
    //assert (InputFile != NULL);

    while (i < str_num)
    {

        while ((sym = getc (InputFile)) != '\n')
        {
            sym_cnt++;
        }

        fseek (InputFile, -(sym_cnt + 1), SEEK_CUR);

        if (getstring (InputFile, &PtrArr[i], 700) != '\n')
        {
            printf ("%d %s\n", i, PtrArr[i]);
            i++;
        }
    }

    free (PtrArr);

    return 0;
}
