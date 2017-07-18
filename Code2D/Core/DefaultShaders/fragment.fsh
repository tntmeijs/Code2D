#version 330 core

in vec2 v_TextureCoordinate;

uniform sampler2D u_Texture;

void main()
{
    gl_FragColor = texture2D(u_Texture, v_TextureCoordinate);
    //gl_FragColor = vec4(0.0, v_TextureCoordinate, 1.0);
}
