/*
** SHADER_VIEWER PROJECT
** MAY 2021
** File description:
** include
*/

#ifndef SHADER_H
#define SHADER_H

#include <SFML/Graphics.h>
#include <math.h>

#include "blib.h"

#define W_WIDTH     1080
#define W_HEIGHT    540
#define IMAGE_NAME  "./ressources/image.png"

typedef struct {
    sfRenderStates states;
    sfShader *tab[4];
    // const sfTexture *text;
    // sfSprite *sprite;
} shader_t;

typedef struct {
    sfClock *clock;
    float seconds;
} time_elapsed_t;

typedef struct {
    sfRenderWindow *window;
    sfRenderTexture *buffer;
    sfEvent event;
    shader_t *shader;
    time_elapsed_t *time;
    int curr;
} engine_t;

sfRenderWindow *create_my_window(int width, int height);
engine_t *init_engine(void);
void destroy_engine(engine_t *engine);

time_elapsed_t *init_time(void);
void destroy_time(time_elapsed_t *time);

shader_t *init_shader(void);
void destroy_shader(shader_t *shader);


#endif // SHADER_H
