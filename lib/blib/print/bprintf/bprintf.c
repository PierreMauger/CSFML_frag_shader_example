/*
** EPITECH PROJECT, 2020
** bprintf.c
** File description:
** 24/03/2021
*/

#include "blib.h"

static params_t ptr_func[] = {
    {"%d", 2, bprint_nbr},
    {"%i", 2, bprint_nbr},
    {"%s", 2, bprint_str},
    {"%c", 2, bprint_char}
};

int bprintf(char *str, ...)
{
    size_t len = bstrlen(str);
    va_list list;
    size_t j = 0;

    va_start(list, str);
    for (size_t i = 0; i < len; i++) {
        for (j = 0; j < ARRAY_SIZE(ptr_func); j++) {
            if (!bstrncmp(ptr_func[j].str, str + i, ptr_func[j].len)) {
                ptr_func[j].ptr(va_arg(list, size_t));
                i += ptr_func[j].len - 1;
                break;
            }
        }
        if (j == ARRAY_SIZE(ptr_func))
            bprint_char(str[i]);
    }
}
