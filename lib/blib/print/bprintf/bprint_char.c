/*
** EPITECH PROJECT, 2020
** bprint_nbr.c
** File description:
** 24/03/2021
*/

#include "blib.h"

void bprint_char(size_t cara)
{
    char c = (int)cara;

    write(1, &c, 1);
}
