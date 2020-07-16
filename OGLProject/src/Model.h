#pragma once

#include"Mesh.h"

class Model
{
private:
	Material * material;
	Texture* texDiffuse;
	Texture* texSpecular;
	std::vector<Mesh*> meshes;
	glm::vec3 position;

public:
	Model(
		glm::vec3 position,
		Material* material,
		Texture* orTexDif,
		Texture* orTexSpec,
		std::vector<Mesh*>& meshes
	);

	~Model();

	//Functions
	void rotate(const glm::vec3 rotation);

	void render(Shader* shader);
};