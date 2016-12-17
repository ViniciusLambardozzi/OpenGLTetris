#pragma once

#include "Buffer.h"

namespace tetris
{
	struct Vertex
	{
		glm::vec3 Position;
		glm::vec3 Color;
	};

	class ArrayBuffer : public Buffer
	{	
	public:
		void Bind() override;

		void BufferData(std::vector<Vertex> BufferData);
	};
}
