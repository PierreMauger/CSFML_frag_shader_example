/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

char **barray_dup(char **src)
{
    size_t src_len = barray_len(src);
    char **result = bcalloc(sizeof(char *), src_len + 1);

    if (!result)
        return NULL;
    for (size_t i = 0; i < src_len; i++) {
        result[i] = bstrdup(src[i]);
    }
    return result;
}
