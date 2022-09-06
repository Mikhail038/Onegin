
#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int str_in_f (FILE* stream);

int sym_in_f (FILE* stream);

void separate_buf (FILE* stream, char** arr, char* buf, int n);


char getstring (FILE* stream, char** str, int n);

void free_arr (int n, void** Arr);

#endif
