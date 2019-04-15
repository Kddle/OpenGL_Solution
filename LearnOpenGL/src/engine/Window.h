#include<glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
private:
	char* title;
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
	char* getTitle();
	int getWidth();
	int getHeight();
	bool isResized();
	bool isVSync();

public:
	Window(char* title, int width, int height, bool vSync);
	void init();
	void update();

};