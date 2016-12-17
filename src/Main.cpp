#include "Common.h"

#include "window\Window.h"

#include "graphics\ShaderProgram.h"

#include "graphics\Mesh.h"

#include "graphics\Renderer.h"

#include "game/Tetris.h"

#include "graphics\Mesh.h"

int main()
{
	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	tetris::Window Tetris("TETRIS", 500, 900);
	Tetris.BindContext();

	glewExperimental = true;
	glewInit();

	glViewport(0, 0, 500, 900);

	const GLchar* VertexSource =
		"#version 330 core\n"
		"layout (location = 0) in vec3 Position;\n"
		"layout (location = 1) in vec3 Color;\n"
		"uniform mat4 projection;\n"
		"uniform mat4 model;\n"
		"out vec3 FragColor;\n"
		"void main()\n"
		"{\n"
		"gl_Position = projection * model * vec4(Position, 1.0f);\n"
		"FragColor = Color;\n"
		"}\n\0";

	const GLchar* FragSource =
		"#version 330 core\n"
		"in vec3 FragColor;\n"
		"out vec4 Color;\n"
		"void main()\n"
		"{\n"
		"Color = vec4(FragColor, 1.0f);\n"
		"}\n\0";

	tetris::ShaderProgram Shader(&VertexSource, &FragSource);
	Shader.Enable();

	Shader.LoadProjectionMatrix(glm::ortho(0.0f , (float)Tetris.GetWidth(), 0.0f, (float)Tetris.GetHeight(), -100.0f, 100.0f));

	tetris::Tetris Game(glm::vec3(Tetris.GetWidth(), Tetris.GetHeight(), 0.0f));

	GLfloat LastFrame = 0.0f;
	GLfloat DeltaTime = 0.0f;

	while (!Tetris.ShouldClose())
	{
		GLfloat CurrentFrame = glfwGetTime();
		DeltaTime = CurrentFrame - LastFrame;
		LastFrame = CurrentFrame;
		glfwPollEvents();
		Tetris.Update();

		Game.Update(DeltaTime);

		std::vector<std::pair<glm::mat4, tetris::Mesh*>> Tiles = Game.GetTileModelPairs();

		auto it = Tiles.begin();

		while (it != Tiles.end())
		{
			Shader.LoadModelMatrix(it->first);
			tetris::Renderer::Render(it->second);
			it++;
		}

		glfwSwapBuffers(Tetris.GetHandle());
	}

	return 0;
}