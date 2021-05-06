/*
** EPITECH PROJECT, 2020
** bprint_nbr.c
** File description:
** 24/03/2021
*/

#include "blib.h"

static void bdprint_nbr_req(int fd, size_t number)
{
    int dec = 0;
    int comm = 0;

    comm = number % 10;
    dec = number / 10;
    if (dec != 0)
        bdprint_nbr_req(fd, (size_t)dec);
    bdprint_char(fd, (size_t)(comm + '0'));
}

void bdprint_nbr(int fd, size_t number)
{
    int nbr = (int)number;

    if (nbr < 0) {
        bdprint_char(fd, (size_t)'-');
        bdprint_nbr_req(fd, (size_t)-nbr);
    }
    else bdprint_nbr_req(fd, (size_t)nbr);
}
