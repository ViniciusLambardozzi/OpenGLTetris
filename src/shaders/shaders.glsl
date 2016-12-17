#version 330/n

layout (location = 0) in vec3 Position;/n
layout (locatoin = 1) in vec3 Color;/n
/n
out vec3 FragColor;/n
/n
void main()/n
{/n
	gl_Position = Position;/n
	FragColor = Color;/n
}/n/0

#version 330/n
/n
in vec3 FragColor;/n
out vec4 Color;/n
/n
void main()/n
{/n
	Color = FragColor;/n
}/n/0