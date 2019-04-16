#pragma once
#include <glad/glad.h>
#include "Renderer.h"

using namespace Kaddle::Game;

void Renderer::init() 
{

}

void Renderer::clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}