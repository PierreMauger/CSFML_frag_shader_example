/*
** EPITECH PROJECT, 2020
** bfprint_str.c
** File description:
** 24/03/2021
*/

#include "blib.h"

void bfprint_str(FILE *stream, size_t str)
{
    char *string = (char *)str;
    size_t len = bstrlen(string);

    fwrite(string, sizeof(char), len, stream);
}
