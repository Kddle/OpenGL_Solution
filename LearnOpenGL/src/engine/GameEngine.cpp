#pragma once
#include "GameEngine.h"

using namespace Kaddle::Engine;

GameEngine::GameEngine(const char* windowTitle, int width, int height, bool vSync, GameLogic* gameLogic)
{
	window = Window(windowTitle, width, height, vSync);
	this->gameLogic = gameLogic;
	timer = Timer();
}

void GameEngine::start()
{
	gameLoopThread = std::thread([this] { run(); });
}

void GameEngine::run()
{
	try
	{
		init();
		gameLoop();
	}
	catch (std::exception ex)
	{
		std::cout << "Error running game engine : " << ex.what() << std::endl;
	}
}

void GameEngine::init()
{
	window.init();
	timer.init();
	gameLogic->init();
}

void GameEngine::gameLoop()
{
	float elapsedTime;
	float accumulator = 0.0f;
	float interval = 1.0f / TARGET_UPS;

	bool running = true;

	while (running && !window.windowShouldClose())
	{
		elapsedTime = timer.getElapsedTime();
		accumulator += elapsedTime;

		input();

		while (accumulator >= interval)
		{
			update(interval);
			accumulator -= interval;
		}

		render();

		if (!window.isVSync())
		{
			sync();
		}
	}
}

void GameEngine::update(float interval)
{
	gameLogic->update(interval);
}

void GameEngine::sync()
{
	float loopSlot = 1.0f / TARGET_FPS;
	double endTime = timer.getLastLoopTime() + loopSlot;
	while (timer.getTime() < endTime)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}

void GameEngine::input()
{
	gameLogic->input(&window);
}

void GameEngine::render()
{
	gameLogic->render(&window);
	window.update();
}