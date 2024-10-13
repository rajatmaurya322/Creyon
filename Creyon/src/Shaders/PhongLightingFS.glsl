#version 430 core

in vec3 normal;
in vec3 fragmentPosition;
in vec3 lightPosition;

out vec4 fragmentColor;

uniform vec3 objectColor;
uniform vec3 lightColor;

void main() {
	
	float ambientIntensity = 0.1f;
	vec3 ambient = ambientIntensity * lightColor;

	vec3 normalizedNormal = normalize(normal);
	vec3 lightDirection = normalize(lightPosition - fragmentPosition);
	float diffuseImpact = max(dot(lightDirection, normalizedNormal), 0.0);
	vec3 diffuse = diffuseImpact * lightColor;

	float specularIntensity = 0.5f;
	//In view space, camera is at origin
	vec3 viewDirection = normalize(-fragmentPosition);
	vec3 reflectedLightDirection = reflect(-lightDirection, normalizedNormal);
	float specularImpact = pow(max(dot(viewDirection, reflectedLightDirection),0.0), 32);
	vec3 specular = specularIntensity * specularImpact * lightColor;

	fragmentColor = vec4((diffuse + ambient + specular) * objectColor, 1.0f);
}