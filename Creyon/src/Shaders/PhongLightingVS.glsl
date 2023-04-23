#version 430 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexcoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat3 normalmat;

out vec3 normal;
out vec3 FragPos;
out vec2 Texcoords;

void main()
{
gl_Position= vec4(aPos, 1.0) * model* view * projection;
normal = aNormal * normalmat;
FragPos = vec3(vec4(aPos, 1.0) * model * view);
Texcoords = aTexcoords;
}