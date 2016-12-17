#pragma once

#include "Common.h"

namespace tetris
{
	class Input
	{
	private:
		bool keys[1024];

	public:
		static Input Instance;

		bool IsKeyDown(int Key) { return keys[Key]; }

		friend void KeyCallback(GLFWwindow* Window, int Key, int Scancode, int Action, int Mode);
	};

	void KeyCallback(GLFWwindow* Window, int Key, int Scancode, int Action, int Mode)
	{
		Input::Instance.keys[Key] = Action != GLFW_RELEASE;
	}
}
