#version 430 core

struct Material{
	sampler2D diffuse;
	sampler2D specular;
	float shininess;
};

struct DirectionalLight{
	vec3 direction;
	vec3 ambient, diffuse, specular; //Intensities of the three components 
};

struct PointLight{
	vec3 position;
	vec3 ambient, diffuse, specular;
	float linear, quadratic; //constants for attentuation
};

vec3 calculateDirectionalLight(DirectionalLight light, vec3 normal);
vec3 calculatePointLight(PointLight light, vec3 normal, vec3 fragmentPosition);

in vec3 fragmentPosition;
in vec3 normal;
in vec2 textureCoords;

out vec4 fragmentColor;

uniform Material material;
uniform DirectionalLight directionalLight;

void main(){
	vec3 resultantColor = calculateDirectionalLight(directionalLight, normal);
	fragmentColor = vec4(resultantColor, 1.0);
}

vec3 calculateDirectionalLight(DirectionalLight light, vec3 normal){
	vec3 diffuseColor = vec3(texture(material.diffuse, textureCoords));
	vec3 ambient = light.ambient * diffuseColor;
	
	vec3 normalizedNormal = normalize(normal);
	vec3 lightDirection = normalize(-light.direction);
	float diffuseImpact = max(dot(normalizedNormal, lightDirection),0.0);
	vec3 diffuse = light.diffuse * diffuseImpact * diffuseColor;

	vec3 reflectedLightDirection = reflect(-lightDirection, normalizedNormal);
	//In view space, camera is at origin
	vec3 viewDirection = normalize(-fragmentPosition);
	float specularImpact = pow( max( dot(reflectedLightDirection, viewDirection),0.0), material.shininess);
	vec3 specular = light.specular * specularImpact * vec3(texture(material.specular, textureCoords));
	return ambient + diffuse + specular;
}

vec3 calculatePointLight(PointLight light, vec3 normal, vec3 fragmentPosition){
	vec3 diffuseColor = vec3(texture(material.diffuse, textureCoords));
	vec3 ambient = light.ambient * diffuseColor;
	
	vec3 normalizedNormal = normalize(normal);
	vec3 lightDirection = normalize(light.position - fragmentPosition);
	float diffuseImpact = max(dot(lightDirection, normalizedNormal), 0.0);
	vec3 diffuse = light.diffuse * diffuseImpact * diffuseColor;
	
	vec3 reflectedLightDirection = reflect(-lightDirection, normalizedNormal);
	//In view space, camera is at origin
	vec3 viewDirection = normalize(-fragmentPosition);
	float specularImpact = pow(max(dot(reflectedLightDirection, viewDirection),0.0), material.shininess);
	vec3 specular = light.specular * specularImpact * vec3(texture(material.specular, textureCoords));
	
	//attenuation for point light
	float lightDistance = length(light.position - fragmentPosition);
	float attenuation = 1.0 /(1.0 + light.linear * lightDistance + light.quadratic * lightDistance * lightDistance);

	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;
	
	return ambient + diffuse + specular;
}