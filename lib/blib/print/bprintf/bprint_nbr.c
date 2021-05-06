/*
** EPITECH PROJECT, 2020
** bprint_nbr.c
** File description:
** 24/03/2021
*/

#include "blib.h"

static void bprint_nbr_req(size_t number)
{
    int dec = 0;
    int comm = 0;

    comm = number % 10;
    dec = number / 10;
    if (dec != 0)
        bprint_nbr_req(dec);
    bprint_char(comm + '0');
}

void bprint_nbr(size_t number)
{
    int nbr = (int)number;

    if (nbr < 0) {
        bprint_char('-');
        bprint_nbr_req((size_t)-nbr);
    }
    else bprint_nbr_req((size_t)nbr);
}
