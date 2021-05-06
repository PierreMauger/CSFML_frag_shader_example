/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

void *bcalloc(size_t nmemb, size_t size)
{
    void *result = malloc(nmemb * size);

    if (result) {
        bmemset(result, 0, nmemb * size);
    }
    return result;
}
