/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

static int batoi_sign(char **str)
{
    int sign = 1;

    for (; **str == '-' || **str == '+'; *str += sizeof(char)) {
        if (**str == '-')
            sign *= -1;
    }
    return sign;
}

int batoi(char *str)
{
    int result = 0;
    int sign = batoi_sign(&str);

    for (int i = 0; str[i] && (str[i] >= '0' && str[i] <= '9'); i++) {
        result *= 10;
        result += str[i] - '0';
    }
    return result * sign;
}
