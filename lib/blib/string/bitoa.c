/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 26/03/2021
*/

#include "blib.h"

static int get_int_size(int nbr)
{
    int i = 0;

    if (nbr < 0)
        i++;
    while (nbr != 0) {
        nbr /= 10;
        i++;
    }
    return i;
}

char *bitoa(int nbr)
{
    int len = get_int_size(nbr);
    char *str = malloc(sizeof(char) * len + 1);
    int i = 0;

    if (!str)
        return NULL;
    if (nbr < 0) {
        str[get_int_size(nbr) - 1] = '-';
        nbr *= -1;
    }
    for (int j = 0; nbr != 0; i++) {
        j = nbr % 10;
        nbr /= 10;
        str[i] = j + '0';
    }
    str[len] = '\0';
    return brevstr(str);
}
