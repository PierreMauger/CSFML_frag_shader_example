/*
** EPITECH PROJECT, 2020
** bfprint_str.c
** File description:
** 24/03/2021
*/

#include "blib.h"

void bdprint_str(int fd, size_t str)
{
    size_t len = bstrlen((char *)str);

    write(fd, (const void *)str, len);
}
