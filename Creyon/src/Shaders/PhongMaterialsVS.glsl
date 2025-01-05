#version 430 core

layout (location=0) in vec3 positions;
layout (location=1) in vec3 normalCoords;
layout (location=2) in vec2 texCoords;

out vec3 fragmentPosition;
out vec3 normal;
out vec2 textureCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform mat3 normalMat;

void main(){
	gl_Position = vec4(positions,1.0) * model * view * projection;
	fragmentPosition = vec3(vec4(positions,1.0) * model * view);
	normal = normalCoords * normalMat;
	textureCoords = texCoords;
}