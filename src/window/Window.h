#pragma once

#include "../Common.h"

namespace tetris
{
	class Window
	{
	private:
		GLFWwindow* m_Handle;

		std::string m_Title;
		int m_Width;
		int m_Height;

	public:
		
		Window(std::string Title, int Width, int Height);
		virtual ~Window();

		virtual void Update();
		virtual void Clear ();
		virtual void Render();

		inline void BindContext() { glfwMakeContextCurrent(m_Handle); }

		inline GLFWwindow* GetHandle() const { return m_Handle; }
		inline int GetWidth() const { return  m_Width; }
		inline int GetHeight() const { return m_Height; }

		inline bool ShouldClose() const { return glfwWindowShouldClose(m_Handle) == GLFW_TRUE; }

	};
}
