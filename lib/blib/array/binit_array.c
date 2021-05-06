/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

char **binit_array(size_t x, size_t y)
{
    char **array = binit_array_light(x);

    if (!array)
        return NULL;
    for (size_t i = 0; i < x; i++) {
        array[i] = bcalloc(sizeof(char), y + 1);
        if (!array[i])
            return NULL;
    }
    array[x] = NULL;
    return array;
}

char **binit_array_light(size_t x)
{
    char **array = bcalloc(sizeof(char *), x + 1);

    if (!array)
        return NULL;
    array[x] = NULL;
    return array;
}
