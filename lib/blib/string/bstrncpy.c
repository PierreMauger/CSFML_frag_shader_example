/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

char *bstrncpy(char *dest, char *src, size_t n)
{
    if (!dest || !src)
        return NULL;
    for (size_t adv = 0; adv < n && src[adv]; adv++) {
        dest[adv] = src[adv];
    }
    return dest;
}
