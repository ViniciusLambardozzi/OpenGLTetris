#include "ArrayBuffer.h"

namespace tetris
{
	void ArrayBuffer::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, m_Handle);
	}

	void ArrayBuffer::BufferData(std::vector<Vertex> BufferData)
	{
		glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * BufferData.size(), (void*)&BufferData[0], GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)(3 * sizeof(GLfloat)));

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
	}

}
