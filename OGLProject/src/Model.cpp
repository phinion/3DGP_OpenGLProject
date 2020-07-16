#include "Model.h"

Model::Model(
	glm::vec3 position,
	Material* material,
	Texture* orTexDif,
	Texture* orTexSpec,
	std::vector<Mesh*>& meshes
)
{
	this->position = position;
	this->material = material;
	this->texDiffuse = orTexDif;
	this->texSpecular = orTexSpec;

	for (auto* i : meshes)
	{
		this->meshes.push_back(new Mesh(*i));
	}

	for (auto& i : this->meshes)
	{
		i->move(this->position);
		i->setOrigin(this->position);
	}
}

Model::~Model()
{
	for (auto*& i : this->meshes)
		delete i;
}

//Functions
void Model::rotate(const glm::vec3 rotation)
{
	for (auto& i : this->meshes)
		i->rotate(rotation);
}

void Model::render(Shader* shader)
{

	//Update uniforms
	this->material->sendToShader(*shader);

	//Use a program
	shader->use();

	//Activate texture
	this->texDiffuse->bind(0);
	this->texSpecular->bind(1);

	//Draw
	for (auto& i : this->meshes)
		i->render(shader);
}