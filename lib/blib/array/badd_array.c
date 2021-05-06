/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

char **badd_array(char **dest, char *src)
{
    size_t len_dest = barray_len((char **)dest);
    char **result = NULL;

    if (!dest || !src)
        return NULL;
    result = binit_array_light(len_dest + 1);
    if (!result)
        return NULL;
    for (size_t i = 0; dest[i]; i++) {
        result[i] = dest[i];
    }
    result[len_dest] = src;
    free(dest);
    dest = result;
    return dest;
}
