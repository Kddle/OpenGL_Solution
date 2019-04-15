#include <iostream>
#include<glad/glad.h>
#include <GLFW/glfw3.h>

GLFWwindow* window;

int init();
void loop();
void run();

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);


int main()
{
	run();
}

void run() {
	if (init() == 0)
	{
		loop();

		glfwDestroyWindow(window);

		glfwTerminate();
		glfwSetErrorCallback(NULL);
	}
}

void loop() {
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

int init() {
	if (!glfwInit())
	{
		std::cout << "Unable to initialize GLFW" << std::endl;
		return -1;
	}

	std::cout << "GLFW Loaded ! Using version : " << glfwGetVersionString() << " !" << std::endl;

	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);

	window = glfwCreateWindow(300, 300, "Hello Yolo World", NULL, NULL);

	if (window == nullptr)
	{
		std::cout << "Failed to create the GLFW Window" << std::endl;
		return -1;
	}

	glfwSetKeyCallback(window, key_callback);

	//
	int pWidth;
	int pHeight;

	glfwGetWindowSize(window, &pWidth, &pHeight);

	const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	glfwSetWindowPos(window, (vidmode->width - pWidth) / 2, (vidmode->height - pHeight) / 2);
	//

	glfwMakeContextCurrent(window);

	// Initialize GLAD before calling any OpenGL functions
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to intialize GLAD" << std::endl;
		return -1;
	}

	glfwSwapInterval(1);
	glfwShowWindow(window);

	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_RELEASE)
		glfwSetWindowShouldClose(window, true);
}