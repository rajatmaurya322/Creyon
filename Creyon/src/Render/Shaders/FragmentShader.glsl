#version 430 core
out vec4 FragColor;

uniform vec3 lightColor;
uniform vec3 objectColor;
uniform vec3 lightPos;

in vec3 normal;
in vec3 FragPos;

void main()
{
float ambientstrength = 0.1;
vec3 ambient = ambientstrength * lightColor;

vec3 norm = normalize(normal);
vec3 lightDir = normalize(lightPos - FragPos);

float diff = max(dot(lightDir, norm), 0.0);
vec3 diffuse = diff * lightColor;

float specularstrength = 0.5;
vec3 viewDir = normalize(-FragPos);
vec3 reflectDir = reflect(-lightDir, norm);

float spec = pow(max(dot(viewDir, reflectDir), 0.0), 64);
vec3 specular = specularstrength * spec * lightColor;

FragColor = vec4((ambient+ diffuse + specular)*objectColor, 1.0);
}