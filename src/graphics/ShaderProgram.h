#pragma once

#include "../Common.h"

namespace tetris
{
	class ShaderProgram
	{
	private:
		GLuint m_Handle;

	public:
		ShaderProgram(const GLchar** VertexShaderCharSource, const GLchar** FragmentShaderCharSource);
		~ShaderProgram();

		void LoadProjectionMatrix(glm::mat4 Projection);
		void LoadModelMatrix(glm::mat4 Model);

		inline void Enable() const { glUseProgram(m_Handle); }
	};
}
