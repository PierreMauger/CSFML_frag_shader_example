/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

size_t barray_len(char **array)
{
    size_t result = 0;

    if (array)
        for (; array[result]; result++);
    return result;
}
