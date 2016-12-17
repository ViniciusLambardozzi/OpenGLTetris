#pragma once

#include "../Common.h"

namespace tetris
{
	class Buffer
	{
	protected:
		GLuint m_Handle;

	public:
		Buffer();
		~Buffer();

		virtual void Bind() = 0;
	};
}
