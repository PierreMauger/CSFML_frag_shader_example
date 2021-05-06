/*
** SHADER_VIEWER PROJECT
** MAY 2021
** File description:
** main
*/

#include "shader.h"

int main(void)
{
    engine_t *engine = init_engine();

    sfTexture *tex = sfTexture_createFromFile(IMAGE_NAME, NULL);
    const sfTexture *temp;
    sfSprite *stemp = sfSprite_create();
    sfSprite *sprite = sfSprite_create();
    sfFloatRect sprite_size = {0};

    sfTexture_setSmooth(tex, sfTrue);
    sfSprite_setTexture(sprite, tex, sfTrue);
    sprite_size = sfSprite_getGlobalBounds(sprite);
    sfSprite_setOrigin(sprite, (sfVector2f){sprite_size.width / 2, sprite_size.height / 2});
    while (sfRenderWindow_isOpen(engine->window)) {
        while (sfRenderWindow_pollEvent(engine->window, &engine->event)) {
            if (engine->event.type == sfEvtClosed)
                sfRenderWindow_close(engine->window);
        }
        engine->time->seconds += sfTime_asSeconds(sfClock_restart(engine->time->clock));
        //for shader 10
        // if (sfMouse_isButtonPressed(sfMouseLeft))
        //     sfShader_setFloatUniform(shader, "glowness", 0.8);
        // else
        //     sfShader_setFloatUniform(shader, "glowness", 0.5);
        // sfShader_setFloatUniform(shader, "mouse_x", sfMouse_getPositionRenderWindow(window).x);
        // sfShader_setFloatUniform(shader, "mouse_y", sfMouse_getPositionRenderWindow(window).y);
        // sfShader_setFloatUniform(shader, "height", 3);
        //for shader 10
        sfShader_setFloatUniform(engine->shader->tab[0], "time", engine->time->seconds);
        sfSprite_setPosition(sprite, (sfVector2f){W_WIDTH / 2, W_HEIGHT / 2});
        sfRenderTexture_clear(engine->buffer, sfColor_fromRGBA(127, 127, 127, 255));
        sfRenderTexture_drawSprite(engine->buffer, sprite, NULL);
        sfRenderTexture_display(engine->buffer);
        temp = sfRenderTexture_getTexture(engine->buffer);
        sfSprite_setTexture(stemp, temp, sfFalse);
        sfRenderWindow_drawSprite(engine->window, stemp, &engine->shader->states);
        sfRenderWindow_display(engine->window);
    }
    destroy_engine(engine);
    sfSprite_destroy(sprite);
    sfSprite_destroy(stemp);
    sfTexture_destroy(tex);
    return 0;
}
