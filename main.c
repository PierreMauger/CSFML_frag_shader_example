/*
** SHADER_VIEWER PROJECT
** MAY 2021
** File description:
** main
*/

#include "shader.h"

//#define SHADER_NAME     "./ressources/example_001.frag"
//#define SHADER_NAME     "./ressources/example_002.frag"
#define SHADER_NAME     "./ressources/example_011.frag"
//#define SHADER_NAME     "./ressources/example_004.frag"
//#define SHADER_NAME     "./ressources/example_005.frag"
//#define SHADER_NAME     "./ressources/example_007.frag"
#define IMAGE_NAME      "./ressources/image.png"
#define WINDOW_WIDTH    1080
#define WINDOW_HEIGHT   540

sfRenderWindow *create_my_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, "Shader example",
    sfVideoMode_isValid(video_mode) ? sfDefaultStyle : sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

int main()
{
    sfRenderWindow *window = create_my_window(WINDOW_WIDTH, WINDOW_HEIGHT);
    sfTexture *tex = sfTexture_createFromFile(IMAGE_NAME, NULL);
    const sfTexture *temp;
    sfSprite *stemp = sfSprite_create();
    sfSprite *sprite = sfSprite_create();
    sfRenderTexture *buffer = sfRenderTexture_create(WINDOW_WIDTH, WINDOW_HEIGHT, sfFalse);
    sfFloatRect sprite_size = {0, 0, 0, 0};
    sfShader *shader = sfShader_createFromFile(NULL, NULL, SHADER_NAME);
    sfClock *time = sfClock_create();
    float seconds = 0;
    sfEvent event;
    sfRenderStates states = {
        .shader = shader,
        .blendMode = sfBlendAlpha,
        .transform = sfTransform_Identity,
        .texture = NULL,
    };

    sfTexture_setSmooth(tex, sfTrue);
    sfSprite_setTexture(sprite, tex, sfTrue);
    sprite_size = sfSprite_getGlobalBounds(sprite);
    sfSprite_setOrigin(sprite, (sfVector2f){sprite_size.width / 2, sprite_size.height / 2});
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        seconds += sfTime_asSeconds(sfClock_restart(time));
        //for shader 10
        // if (sfMouse_isButtonPressed(sfMouseLeft))
        //     sfShader_setFloatUniform(shader, "glowness", 0.8);
        // else
        //     sfShader_setFloatUniform(shader, "glowness", 0.5);
        // sfShader_setFloatUniform(shader, "mouse_x", sfMouse_getPositionRenderWindow(window).x);
        // sfShader_setFloatUniform(shader, "mouse_y", sfMouse_getPositionRenderWindow(window).y);
        // sfShader_setFloatUniform(shader, "height", 3);
        //for shader 10
        sfShader_setFloatUniform(shader, "time", seconds);
        sfSprite_setPosition(sprite, (sfVector2f){WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
        sfRenderTexture_clear(buffer, sfColor_fromRGBA(127, 127, 127, 255));
        sfRenderTexture_drawSprite(buffer, sprite, NULL);
        sfRenderTexture_display(buffer);
        temp = sfRenderTexture_getTexture(buffer);
        sfSprite_setTexture(stemp, temp, sfFalse);
        sfRenderWindow_drawSprite(window, stemp, &states);
        sfRenderWindow_display(window);
    }
    return 0;
}
