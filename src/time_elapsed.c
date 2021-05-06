/*
** SHADER_VIEWER PROJECT
** MAY 2021
** File description:
** time_elapsed
*/

#include "shader.h"

time_elapsed_t *init_time(void)
{
    time_elapsed_t *time = malloc(sizeof(time_elapsed_t));

    time->clock = sfClock_create();
    time->seconds = 0;
    return time;
}

void destroy_time(time_elapsed_t *time)
{
    sfClock_destroy(time->clock);
    free(time);
}
