#include "ShaderProgram.h"

namespace tetris
{
	ShaderProgram::ShaderProgram(const GLchar** VertexShaderCharSource, const GLchar** FragmentShaderCharSource)
	{
		GLuint VertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(VertexShader, 1, VertexShaderCharSource, NULL);
		glCompileShader(VertexShader);

		GLint ShaderStatus;
		GLchar ErrorInfo[512];
		glGetShaderiv(VertexShader, GL_COMPILE_STATUS, &ShaderStatus);
		if (!ShaderStatus)
		{
			glGetShaderInfoLog(VertexShader, 512, NULL, ErrorInfo);
			std::cout << "Erro compilando vertex shader: " << std::endl;
			std::cout << ErrorInfo << std::endl;
		}


		GLuint FragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(FragmentShader, 1, FragmentShaderCharSource, NULL);
		glCompileShader(FragmentShader);

		glGetShaderiv(FragmentShader, GL_COMPILE_STATUS, &ShaderStatus);
		if (!ShaderStatus)
		{
			glGetShaderInfoLog(FragmentShader, 512, NULL, ErrorInfo);
			std::cout << "Erro compilando fragment shader: " << std::endl;
			std::cout << ErrorInfo << std::endl;
		}

		m_Handle = glCreateProgram();
		glAttachShader(m_Handle, VertexShader);
		glAttachShader(m_Handle, FragmentShader);
		glLinkProgram(m_Handle);

		glDeleteShader(VertexShader);
		glDeleteShader(FragmentShader);
	}
	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(m_Handle);
	}
	void ShaderProgram::LoadProjectionMatrix(glm::mat4 Projection)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_Handle, "projection"), 1, GL_FALSE, glm::value_ptr(Projection));
	}
	void ShaderProgram::LoadModelMatrix(glm::mat4 Model)
	{
		glUniformMatrix4fv(glGetUniformLocation(m_Handle, "model"), 1, GL_FALSE, glm::value_ptr(Model));

	}
}