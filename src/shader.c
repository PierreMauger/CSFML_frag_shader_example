/*
** SHADER_VIEWER PROJECT
** MAY 2021
** File description:
** shader
*/

#include "shader.h"

static const char *shader_list[] =
{
    "./ressources/example_001.frag",
    "./ressources/example_002.frag",
    "./ressources/example_003.frag",
    NULL
};

shader_t *init_shader(void)
{
    shader_t *shader = malloc(sizeof(shader_t));
    int i = 0;

    for (; shader_list[i]; i++)
        shader->tab[i] = sfShader_createFromFile(NULL, NULL, shader_list[i]);
    shader->tab[i] = NULL;
    shader->states = (sfRenderStates){
        .shader = shader->tab[0],
        .blendMode = sfBlendAlpha,
        .transform = sfTransform_Identity,
        .texture = NULL,
    };
    return shader;
}

void destroy_shader(shader_t *shader)
{
    for (int i = 0; shader->tab[i]; i++)
        sfShader_destroy(shader->tab[i]);
    free(shader);
}
