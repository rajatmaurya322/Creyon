#version 430 core
layout (location = 0) in vec3 positions;
layout (location = 1) in vec2 texCoords;

out vec2 textureCoordinates;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main(){
	gl_Position= vec4(positions, 1.0) * model * view * projection;
	textureCoordinates = texCoords;
}