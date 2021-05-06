/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

char **bremove_array(char **dest, size_t array_nbr)
{
    size_t len_dest = barray_len(dest);
    char **result = NULL;

    if (!dest || !len_dest || array_nbr > len_dest - 1)
        return NULL;
    result = binit_array_light(len_dest);
    if (!result)
        return NULL;
    for (size_t i = 0; i < array_nbr; i++) {
        result[i] = dest[i];
    }
    for (size_t i = array_nbr + 1; i < len_dest; i++) {
        result[i - 1] = dest[i];
    }
    free(dest[array_nbr]);
    free(dest);
    return result;
}
