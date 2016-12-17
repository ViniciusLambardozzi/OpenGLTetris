#include "ElementArrayBuffer.h"

namespace tetris
{
	void ElementArrayBuffer::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Handle);
	}
	void ElementArrayBuffer::BufferData(std::vector<uint> Indices)
	{
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint) * Indices.size(), &Indices[0], GL_STATIC_DRAW);
	}
}