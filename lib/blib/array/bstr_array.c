/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

static int bcount_line(char *file, char separator)
{
    int result = 0;

    for (int i = 0; file[i]; i++, result++) {
        for (; file[i] != separator && file[i]; i++);
        for (; file[i] == separator && file[i]; i++);
        i--;
    }
    return result;
}

char **bstr_array(char *file, char separator)
{
    char **map = NULL;
    int adv = 0;
    int x = 0;
    int y = 0;

    if (!file)
        return NULL;
    x = bcount_line(file, separator);
    map = bcalloc(sizeof(char *), x + 1);
    if (!map)
        return NULL;
    for (int nb_arr = 0; nb_arr < x; nb_arr++) {
        for (y = 0; file[adv + y] != separator && file[adv + y]; y++);
        map[nb_arr] = bstrndup(file + adv, y);
        for (; file[adv + y] == separator && file[adv + y]; y++);
        adv += y;
    }
    map[x] = NULL;
    return map;
}
