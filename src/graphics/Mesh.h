#pragma once

#include "../Common.h"
#include "VertexArray.h"
#include "ArrayBuffer.h"
#include "ElementArrayBuffer.h"

namespace tetris
{
	class Mesh
	{
	private:
		VertexArray* VAO;
		ArrayBuffer* VBO;
		ElementArrayBuffer* IBO;
		uint m_VertexCount;

	public:
		Mesh(std::vector<glm::vec3> Vertices, std::vector<uint> Indices, glm::vec3 Color, uint VertexCount);
		~Mesh();

		inline void StartEditing() { VAO->Bind(); }
		inline void StopEditing() { } 

		inline VertexArray* GetVAO() { return VAO; }
		inline ElementArrayBuffer* GetIBO() { return IBO; }
		inline uint GetVertexCount() { return m_VertexCount; }
	};

	class MeshFactory
	{
	public:
		static Mesh* CreateQuad(glm::vec3 Position, GLfloat SizeX, GLfloat SizeY, glm::vec3 Color);
	};
}
