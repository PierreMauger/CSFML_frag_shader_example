/*
** EPITECH PROJECT, 2020
** bprint_nbr.c
** File description:
** 24/03/2021
*/

#include "blib.h"

void bfprint_char(FILE *stream, size_t cara)
{
    char c = (int)cara;

    fwrite(&c, sizeof(char), 1, stream);
}
