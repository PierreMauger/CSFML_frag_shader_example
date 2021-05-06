/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

char *bstrncat(char *dest, char *src, size_t n)
{
    size_t i = bstrlen(dest);
    size_t j = 0;

    if (!dest || !src)
        return NULL;
    for (; j < n && src[j]; j++)
        dest[i + j] = src[j];
    dest[i + j] = '\0';
    return dest;
}
