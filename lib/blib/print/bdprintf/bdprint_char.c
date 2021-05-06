/*
** EPITECH PROJECT, 2020
** bprint_nbr.c
** File description:
** 24/03/2021
*/

#include "blib.h"

void bdprint_char(int fd, size_t cara)
{
    char c = (char)cara;

    write(fd, &c, 1);
}
