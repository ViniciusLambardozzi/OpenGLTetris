#pragma once

#include "../Common.h"

namespace tetris
{
	class VertexArray
	{
	private:
		GLuint m_Handle;

	public:
		VertexArray();
		~VertexArray();

		inline void Bind() const { glBindVertexArray(m_Handle); }
	};
}
