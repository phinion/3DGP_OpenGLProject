#pragma once

#include<iostream>
#include<string>

#include<glew.h>
#include<glfw3.h>

#include<SOIL2.h>

class Texture
{
private:
	GLuint id;
	int width;
	int height;
	unsigned int type;

public:

	Texture(const char* fileName, GLenum type);

	~Texture(){glDeleteTextures(1, &this->id);}

	inline GLuint getID() const { return this->id; }

	void bind(const GLint texture_unit);

	void unbind();

	void loadFromFile(const char* fileName);
};