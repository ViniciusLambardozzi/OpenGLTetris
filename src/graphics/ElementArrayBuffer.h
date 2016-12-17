#pragma once

#include "Buffer.h"

namespace tetris
{
	class ElementArrayBuffer : public Buffer
	{
	public:
		void Bind() override;

		void BufferData(std::vector<uint> Indices);
	};
}