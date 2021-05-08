/*
** SHADER_VIEWER PROJECT
** MAY 2021
** File description:
** image
*/

#include "shader.h"

image_t *init_image(void)
{
    image_t *image = malloc(sizeof(image_t));

    image->texture = sfTexture_createFromFile(IMAGE_NAME, NULL);
    image->sprite = sfSprite_create();
    image->sprite_size = (sfFloatRect){0};
    sfTexture_setSmooth(image->texture, sfTrue);
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    image->sprite_size = sfSprite_getGlobalBounds(image->sprite);
    sfSprite_setPosition(image->sprite, (sfVector2f){W_WIDTH / 2, W_HEIGHT / 2});
    sfSprite_setOrigin(image->sprite, (sfVector2f){image->sprite_size.width / 2,
    image->sprite_size.height / 2});
    return image;
}

void destroy_image(image_t *image)
{
    sfTexture_destroy(image->texture);
    sfSprite_destroy(image->sprite);
    free(image);
}
