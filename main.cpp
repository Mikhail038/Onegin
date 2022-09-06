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

    int str_num = str_in_f (InputFile);

    char** PtrArr = NULL;

    PtrArr = (char**) calloc (str_num, sizeof (*PtrArr));
    assert (PtrArr != NULL);

    int buf_size = sym_in_f (InputFile);

    char* Buf = NULL;

    Buf = (char*) calloc (buf_size, sizeof (*Buf));
    assert (Buf != NULL);

    fread (Buf, sizeof (char), buf_size, InputFile);

    fclose (InputFile);


    separate_buf (InputFile, PtrArr, Buf, buf_size);



    //InputFile = fopen ("Onegin.txt", "r");
    //assert (InputFile != NULL);

    /*while (i < str_num)
    {
        sym_cnt = 0;

       // while ((sym = getc (InputFile)) != '\n')
        {
       //     sym_cnt++;
        }

        if (sym_cnt > 0)
            fseek (InputFile, -(sym_cnt + 1 ), SEEK_CUR);

        if (getstring (InputFile, &PtrArr[i], 700 ) != '\n')
        {
            printf ("%d %s\n", i, PtrArr[i]);
            i++;
        }
    }*/

    /*InputFile = fopen ("Onegin.txt", "r");
    assert (InputFile != NULL);

    int i = 0;
    printf ("1 \n");

    fread (&PtrArr[i], sizeof (char), 5, InputFile);
    printf ("2 \n");
    //printf ("3  %c\n", (PtrArr[i])[i]);
    printf ("3  '%c'\n", PtrArr[i]);
    //printf ("3  %s\n", PtrArr[i]);
    printf ("4 \n");*/

    //printf ("!%s", Buf);
    for (int i = 0; i < str_num; i++)
    {
        printf ("%d %s\n", i, PtrArr[i]);
    }

    free_arr (str_num, (void**) PtrArr);
    free (Buf);

    return 0;
}
