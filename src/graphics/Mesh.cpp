#include "Mesh.h"

namespace tetris
{
	Mesh::Mesh(std::vector<glm::vec3> Vertices, std::vector<uint> Indices, glm::vec3 Color, uint VertexCount)
	{
		VAO = new VertexArray();
		StartEditing();


		std::vector<Vertex> ColoredVertices;

		for (int i = 0; i < Vertices.size(); i++)
		{
			Vertex CurrentVertex;
			CurrentVertex.Position = Vertices[i];
			CurrentVertex.Color = Color;

			ColoredVertices.push_back(CurrentVertex);
		}


		VBO = new ArrayBuffer();
		VBO->Bind();
		VBO->BufferData(ColoredVertices);

		IBO = new ElementArrayBuffer();
		IBO->Bind();
		IBO->BufferData(Indices);

		m_VertexCount = VertexCount;

		StopEditing();
	}
	Mesh::~Mesh()
	{
		delete VAO;
		delete VBO;
		delete IBO;
	}
	Mesh* MeshFactory::CreateQuad(glm::vec3 Position, GLfloat SizeX, GLfloat SizeY, glm::vec3 Color)
	{
		std::vector<glm::vec3> Vertices;

		Vertices.push_back(glm::vec3(Position.x - SizeX, Position.y - SizeY, 0.0f));
		Vertices.push_back(glm::vec3(Position.x - SizeX, Position.y + SizeY, 0.0f));
		Vertices.push_back(glm::vec3(Position.x + SizeX, Position.y + SizeY, 0.0f));
		Vertices.push_back(glm::vec3(Position.x + SizeX, Position.y - SizeY, 0.0f));

		std::vector<uint> Indices;
		Indices.push_back(0);
		Indices.push_back(1);
		Indices.push_back(2);

		Indices.push_back(2);
		Indices.push_back(3);
		Indices.push_back(0);

		return new Mesh(Vertices, Indices, Color, 6);
	}
}