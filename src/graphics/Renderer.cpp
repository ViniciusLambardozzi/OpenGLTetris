#include "Renderer.h"

namespace tetris
{
	void Renderer::Render(Mesh* Mesh)
	{
		Mesh->GetVAO()->Bind();
		Mesh->GetIBO()->Bind();

		glDrawElements(GL_TRIANGLES, Mesh->GetVertexCount(), GL_UNSIGNED_INT, 0);
	}
}