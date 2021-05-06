/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

int bstrncmp(char *s1, char *s2, size_t n)
{
    size_t i = 0;

    for (; i < n; i++) {
        if (s1[i] != s2[i] || !s1[i] || !s2[i])
            return s1[i] - s2[i];
    }
    return s1[i - 1] - s2[i - 1];
}
