#pragma once
#include "Window.h"

using namespace Kaddle::Engine;

Window::Window()
{

}

Window::Window(const char* windowTitle, int width, int height, bool vSync)
{
	this->title = windowTitle;
	this->width = width;
	this->height = height;
	this->vSync = vSync;
	this->resized = false;
}

void Window::init()
{
	
}

void Kaddle::Engine::Window::update()
{
}

bool Kaddle::Engine::Window::isKeyPressed(int keyCode)
{
	return false;
}

void Kaddle::Engine::Window::setResized(bool resized)
{
}

void Kaddle::Engine::Window::setClearColor(float r, float g, float b, float a)
{
}

bool Kaddle::Engine::Window::windowShouldClose()
{
	return false;
}

const char * Kaddle::Engine::Window::getTitle()
{
	return nullptr;
}

int Kaddle::Engine::Window::getWidth()
{
	return 0;
}

int Kaddle::Engine::Window::getHeight()
{
	return 0;
}

bool Kaddle::Engine::Window::isResized()
{
	return false;
}

bool Kaddle::Engine::Window::isVSync()
{
	return false;
}
