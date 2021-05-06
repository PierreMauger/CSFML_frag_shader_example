/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

void *bmemset(void *s, int c, size_t n)
{
    unsigned char *ptr = s;

    for (size_t i = 0; i < n; i++) {
        *ptr = c;
        ptr++;
    }
    return s;
}
