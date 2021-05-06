/*
** EPITECH PROJECT, 2020
** blib.c
** File description:
** 24/03/2021
*/

#ifndef BARRAY_H
#define BARRAY_H

#include "bstring.h"
#include "bmemory.h"

size_t barray_len(char **array);

char **binit_array_light(size_t x);
char **binit_array(size_t x, size_t y);

// DUPLICATE A MATRIX
char **barray_dup(char **src);

// SEPARATE A STRING WITH A SEPARATOR IN A MATRIX
char **bstr_array(char *file, char separator);

// ADD AN STRING IN TO AN ARRAY AND RETURN IT
char **badd_array(char **dest, char *src);
// REMOVE AN STRING IN TO AN ARRAY AND RETURN IT
char **bremove_array(char **dest, size_t array_nbr);

void bfree_array(char **src);

#endif // BARRAY_H
