#version 430 core
out vec4 FragColor;

in vec2 textCoord;

uniform sampler2D ourTexture;
uniform sampler2D ourTexture2;

void main()
{
FragColor = mix( texture(ourTexture, textCoord), texture(ourTexture2, textCoord), 0.7);
}