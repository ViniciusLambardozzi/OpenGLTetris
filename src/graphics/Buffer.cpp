#include "Buffer.h"


namespace  tetris
{
	Buffer::Buffer()
	{
		glCreateBuffers(1, &m_Handle);
	}
	
	Buffer::~Buffer()
	{
		glDeleteBuffers(1, &m_Handle);
	}
}
