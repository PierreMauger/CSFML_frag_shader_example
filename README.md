# CSFML_frag_shader_example
A CSFML example for OpenGL fragment shaders on sprites

A mix from differents SFML tutorials translated in CSFML

Needed:

    -SFML 2.5

    -CSFML 2.5

    -math.h

To use:

    -make

    -./shader

    -use arrow keys to go through every shaders

Don't use "sfShader_setFloatParameter" because the function is deprecated,
use "sfShader_setUniform".
