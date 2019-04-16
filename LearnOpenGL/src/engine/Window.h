#pragma once
#include<glad/glad.h>
#include <GLFW/glfw3.h>

namespace Kaddle {
	namespace Engine {

		class Window
		{
		private:
			const char* title;
			GLFWwindow* windowHandle;
			int width;
			int height;
			bool resized;
			bool vSync;

		public:
			bool isKeyPressed(int keyCode);
			void setResized(bool resized);
			void setClearColor(float r, float g, float b, float a);
			bool windowShouldClose();
			const char* getTitle();
			int getWidth();
			int getHeight();
			bool isResized();
			bool isVSync();

		public:
			Window();
			Window(const char* windowTitle, int width, int height, bool vSync);
			void init();
			void update();

		};
	}
}