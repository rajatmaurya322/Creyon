#version 430 core

layout (location = 0) in vec3 positions;
layout (location = 1) in vec3 normalCoords;

out vec3 normal;
out vec3 fragmentPosition;
out vec3 lightPosition;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat3 normalMat;
uniform vec3 lightCoords;

void main() {
	gl_Position= vec4(positions, 1.0f) * model* view * projection;
	
	fragmentPosition = vec3(vec4(positions, 1.0f) * model * view);
	normal = normalCoords * normalMat;
	lightPosition = vec3(vec4(lightCoords, 1.0f) * view); 
}