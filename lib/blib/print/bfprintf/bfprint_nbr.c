/*
** EPITECH PROJECT, 2020
** bprint_nbr.c
** File description:
** 24/03/2021
*/

#include "blib.h"

static void bfprint_nbr_req(FILE *stream, size_t number)
{
    int dec = 0;
    int comm = 0;

    comm = number % 10;
    dec = number / 10;
    if (dec != 0)
        bfprint_nbr_req(stream, (size_t)dec);
    bfprint_char(stream, (size_t)(comm + '0'));
}

void bfprint_nbr(FILE *stream, size_t number)
{
    int nbr = (int)number;

    if (nbr < 0) {
        bfprint_char(stream, (size_t)'-');
        bfprint_nbr_req(stream, (size_t)-nbr);
    }
    else bfprint_nbr_req(stream, (size_t)nbr);
}
