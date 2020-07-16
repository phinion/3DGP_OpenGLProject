#pragma once

#include "libs.h"
#include "Camera.h"

enum shader_enum { SHADER_CORE_PROGRAM = 0 };
enum texture_enum { TEX_PICHU = 0, TEX_PICHU_SPECULAR, TEX_CONTAINER, TEX_CONTAINER_SPECULAR };
enum material_enum { MAT_1 = 0 };
enum mesh_enum { MESH_QUAD = 0 };

class Game
{
private:
	//Window vars
	GLFWwindow* window;
	const int WINDOW_WIDTH;
	const int WINDOW_HEIGHT;
	int frameBufferWidth;
	int frameBufferHeight;

	const int GL_VERSION_MAJOR = 4;
	const int GL_VERSION_MINOR = 4;

	float dt;
	float curTime;
	float lastTime;

	//Mouse Input
	double lastMouseX;
	double lastMouseY;
	double mouseX;
	double mouseY;
	double mouseOffsetX;
	double mouseOffsetY;
	bool firstMouse;

	//Camera
	Camera camera;

	//Matrices
	glm::mat4 viewMatrix;
	glm::vec3 camPosition;
	glm::vec3 worldUp;
	glm::vec3 camFront;

	glm::mat4 projectionMatrix;
	float fov;
	float nearPlane;
	float farPlane;

	//Shaders
	std::vector<Shader*> shaders;

	//Textures
	std::vector<Texture*> textures;

	//Materials
	std::vector<Material*> materials;

	//Models
	std::vector<Model*> models;

	//Lights
	std::vector<glm::vec3*> lights;

	//Functions to inititize variables and setup simulation
	void initGLFW();
	void initWindow(const char* title);
	void initGLEW();
	void initOpenGLOptions();
	void initMatrices();
	void initShaders();
	void initTextures();
	void initMaterials();
	void initModels();
	void initLights();
	void initUniforms();

	void updateUniforms();

public:
	//Constructors / Destructors
	Game(
		const char* title,
		const int WINDOW_WIDTH, const int WINDOW_HEIGHT,
		bool resizable
	);
	virtual ~Game();

	//Accessors
	int getWindowShouldClose();

	void setWindowShouldClose();

	void updateDt();
	void updateMouseInput();
	void updateKeyboardInput();
	void updateInput();
	void update();
	void render();

};