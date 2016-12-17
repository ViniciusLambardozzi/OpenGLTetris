#include "VertexArray.h"

namespace tetris
{
	VertexArray::VertexArray()
	{
		glCreateVertexArrays(1, &m_Handle);
	}
	VertexArray::~VertexArray()
	{
		glDeleteVertexArrays(1, &m_Handle);
	}


}