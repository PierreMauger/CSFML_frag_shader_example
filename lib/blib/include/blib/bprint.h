/*
** EPITECH PROJECT, 2020
** blib.c
** File description:
** 24/03/2021
*/

#ifndef BPRINT_H
#define BPRINT_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#include "blib.h"

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(*x))

typedef struct {
    char *str;
    size_t len;
    void (*ptr)(size_t);
} params_t;

typedef struct {
    char *str;
    size_t len;
    void (*ptr)(FILE *, size_t);
} fparams_t;

typedef struct {
    char *str;
    size_t len;
    void (*ptr)(int, size_t);
} dparams_t;

void bprint_char(size_t cara);
void bfprint_char(FILE *stream, size_t cara);
void bdprint_char(int fd, size_t cara);

void bprint_nbr(size_t number);
void bfprint_nbr(FILE *stream, size_t number);
void bdprint_nbr(int fd, size_t number);

void bprint_str(size_t str);
void bfprint_str(FILE *stream, size_t str);
void bdprint_str(int fd, size_t str);

int bprintf(char *str, ...);
int bfprintf(FILE *stream, char *str, ...);
int bdprintf(int fd, char *str, ...);

#endif // BPRINT_H
