/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 26/03/2021
*/

#include "blib.h"

char *brevstr(char *src)
{
    int j = bstrlen(src) - 1;
    char c;

    for (size_t i = 0; i < bstrlen(src) / 2; i++) {
        c = src[i];
        src[i] = src[j];
        src[j] = c;
        j--;
    }
    return src;
}
