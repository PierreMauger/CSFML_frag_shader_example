/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

char *bstrdup(char *src)
{
    char *cp_src = malloc(sizeof(char) * (bstrlen(src) + 1));
    int i = 0;

    if (!cp_src || !src)
        return NULL;
    for (; src[i]; i++)
        cp_src[i] = src[i];
    cp_src[i] = '\0';
    return cp_src;
}
