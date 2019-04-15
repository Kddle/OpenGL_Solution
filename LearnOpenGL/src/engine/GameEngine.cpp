#include <exception>
#include <iostream>
#include "GameEngine.h"

GameEngine::GameEngine(char* windowTitle, int width, int height, bool vSync, GameLogic* gameLogic)
{
	window = Window(windowTitle, width, height, vSync);
	this->gameLogic = gameLogic;
}

void GameEngine::start()
{
	gameLoopThread = std::thread(run, "GAME_LOOP_THREAD");
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
		std::cout << "Error running game engine : " << ex.what() << endl;
	}
}

void GameEngine::gameLoop()
{
	bool running = true;
	while (running && !window.windowShouldClose())
	{
		input();
		update();
		render();
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