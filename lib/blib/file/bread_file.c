/*
** EPITECH PROJECT, 2020
** blib
** File description:
** 24/03/2021
*/

#include "blib.h"

static char *create_str(char *str, size_t size)
{
    char *result = bstrndup(str, size);

    if (result) {
        bmemset(result + bstrlen(str), '\0', size + 1 - bstrlen(str));
    }
    free(str);
    return result;
}

static char *bloop_read(int fd, char *temp, char *buffer, size_t size_read)
{
    int ret = 1;
    int iter = 0;
    int len = size_read;

    do {
        iter++;
        len = (iter * size_read);
        bmemset(temp, '\0', size_read + 1);
        ret = read(fd, temp, size_read);
        buffer = bstrcat(create_str(buffer, len + ret), temp);
        if (!buffer)
            return NULL;
        if (ret == (int)size_read && !temp[ret - 1])
            break;
    } while (ret == (int)size_read);
    return buffer;
}

char *bread_file(char *path, size_t size_read)
{
    char *temp = malloc(sizeof(char) * (size_read + 1));
    char *buffer = bcalloc(sizeof(char), size_read + 1);
    int fd = open(path, O_RDONLY);

    if (fd == -1 || !temp || !buffer)
        return NULL;
    buffer = bloop_read(fd, temp, buffer, size_read);
    free(temp);
    close(fd);
    return buffer;
}
