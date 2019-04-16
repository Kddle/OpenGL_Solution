#pragma once
#include "HelloGame.h"

using namespace Kaddle::Game;

HelloGame::HelloGame()
{
}

void HelloGame::init()
{
	this->renderer.init();
}

void HelloGame::input(Kaddle::Engine::Window* window)
{
	if (window->isKeyPressed(GLFW_KEY_UP))
	{
		this->direction = 1;
	}
	else if (window->isKeyPressed(GLFW_KEY_DOWN))
	{
		this->direction = -1;
	}
	else
	{
		this->direction = 0;
	}
}

void HelloGame::update(float interval)
{
	this->color += this->direction;
	if (this->color > 1)
	{
		this->color = 1;
	}
	else if (this->color < 0)
	{
		this->color = 0;
	}
}

void HelloGame::render(Kaddle::Engine::Window* window)
{
	if (window->isResized())
	{
		glViewport(0, 0, window->getWidth(), window->getHeight());
		window->setResized(false);
	}
	window->setClearColor(color, color, color, 0.0f);
	renderer.clear();
}