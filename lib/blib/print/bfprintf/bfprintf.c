/*
** EPITECH PROJECT, 2020
** bprintf.c
** File description:
** 24/03/2021
*/

#include "blib.h"

static fparams_t ptr_func[] = {
    {"%d", 2, bfprint_nbr},
    {"%i", 2, bfprint_nbr},
    {"%s", 2, bfprint_str},
    {"%c", 2, bfprint_char}
};

int bfprintf(FILE *stream, char *str, ...)
{
    size_t len = bstrlen(str);
    size_t j = 0;
    va_list list;

    va_start(list, str);
    for (size_t i = 0; i < len; i++) {
        for (j = 0; j < ARRAY_SIZE(ptr_func); j++) {
            if (!bstrncmp(ptr_func[j].str, str + i, ptr_func[j].len)) {
                ptr_func[j].ptr(stream, va_arg(list, size_t));
                i += ptr_func[j].len - 1;
                break;
            }
        }
        if (j == ARRAY_SIZE(ptr_func))
            bfprint_char(stream, (size_t)str[i]);
    }
}
