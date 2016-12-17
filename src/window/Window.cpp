#include "Window.h"

namespace tetris
{
	Window::Window(std::string Title, int Width, int Height)
	{
		m_Handle = glfwCreateWindow(Width, Height, Title.c_str(), NULL, NULL);
		m_Title = Title;
		m_Width = Width;
		m_Height = Height;
		assert(m_Handle);
	}
	Window::~Window()
	{
		glfwDestroyWindow(m_Handle);
	}
	void Window::Update()
	{
		Clear();
		Render();

		//glfwSwapBuffers(m_Handle);
	}
	void Window::Clear()
	{
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}
	void Window::Render()
	{

	}
}