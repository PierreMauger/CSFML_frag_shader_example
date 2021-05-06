/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

size_t bstrlen(char *str)
{
    size_t size_tab = 0;

    if (!str)
        return 0;
    for (; str[size_tab]; size_tab++);
    return size_tab;
}
