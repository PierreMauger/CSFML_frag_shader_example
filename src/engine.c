/*
** SHADER_VIEWER PROJECT
** MAY 2021
** File description:
** engine
*/

#include "shader.h"

sfRenderWindow *create_my_window(int width, int height)
{
    sfRenderWindow *window = NULL;
    sfVideoMode video_mode = {0};

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "Shader_viewer",
    sfVideoMode_isValid(video_mode) ? sfDefaultStyle : sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

engine_t *init_engine(void)
{
    engine_t *engine = malloc(sizeof(engine_t));

    engine->window = create_my_window(W_WIDTH, W_HEIGHT);
    engine->buffer = sfRenderTexture_create(W_WIDTH, W_HEIGHT, sfFalse);
    engine->shader = init_shader();
    engine->time = init_time();
    engine->image = init_image();
    engine->curr = 0;
    engine->event = (sfEvent){0};
    return engine;
}

void destroy_engine(engine_t *engine)
{
    destroy_image(engine->image);
    destroy_time(engine->time);
    destroy_shader(engine->shader);
    sfRenderWindow_destroy(engine->window);
    sfRenderTexture_destroy(engine->buffer);
    free(engine);
}
