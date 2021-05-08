/*
** SHADER_VIEWER PROJECT
** MAY 2021
** File description:
** main
*/

#include "shader.h"

void event_loop(engine_t *engine)
{
    while (sfRenderWindow_pollEvent(engine->window, &engine->event)) {
        if (engine->event.type == sfEvtClosed)
            sfRenderWindow_close(engine->window);
        if (engine->event.type == sfEvtKeyPressed) {
            if (engine->event.key.code == sfKeyLeft && engine->curr)
                engine->curr -= 1;
            if (engine->event.key.code == sfKeyRight && engine->curr < 10)
                engine->curr += 1;
            change_shader(engine);
        }
    }
}

void draw_all(engine_t *engine)
{
        sfRenderTexture_clear(engine->buffer, sfColor_fromRGBA(127, 127, 127, 255));
        sfRenderTexture_drawSprite(engine->buffer, engine->image->sprite, NULL);
        sfRenderTexture_display(engine->buffer);
        engine->shader->texture = sfRenderTexture_getTexture(engine->buffer);
        sfSprite_setTexture(engine->shader->sprite, engine->shader->texture, sfFalse);
        sfRenderWindow_drawSprite(engine->window, engine->shader->sprite, &engine->shader->states);
        sfRenderWindow_display(engine->window);
}

int main(void)
{
    engine_t *engine = init_engine();

    while (sfRenderWindow_isOpen(engine->window)) {
        event_loop(engine);
        engine->time->seconds += sfTime_asSeconds(sfClock_restart(engine->time->clock));
        sfShader_setFloatUniform(engine->shader->tab[engine->curr], "time", engine->time->seconds);
        draw_all(engine);
    }
    destroy_engine(engine);
    return 0;
}

        //for shader 10
        // if (sfMouse_isButtonPressed(sfMouseLeft))
        //     sfShader_setFloatUniform(shader, "glowness", 0.8);
        // else
        //     sfShader_setFloatUniform(shader, "glowness", 0.5);
        // sfShader_setFloatUniform(shader, "mouse_x", sfMouse_getPositionRenderWindow(window).x);
        // sfShader_setFloatUniform(shader, "mouse_y", sfMouse_getPositionRenderWindow(window).y);
        // sfShader_setFloatUniform(shader, "height", 3);
        //for shader 10
