/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 02/04/2021
*/

#include "blib.h"

void bfree_array(char **src)
{
    if (!src)
        return;
    for (size_t i = 0; src[i]; i++) {
        free(src[i]);
    }
    free(src);
}
