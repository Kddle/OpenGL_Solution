#pragma once
#include <iostream>
#include <exception>
#include <thread>
#include <chrono>
#include "GameLogic.h"
#include "Window.h"
#include "Timer.h"

namespace Kaddle {
	namespace Engine {
		class GameEngine
		{
		public:
			static const int TARGET_FPS = 75;
			static const int TARGET_UPS = 30;
		private:
			Window window;
			std::thread gameLoopThread;
			GameLogic* gameLogic;
			Timer timer;

		public:
			GameEngine(const char* windowTitle, int width, int height, bool vSync, GameLogic* gameLogic);
			void start();
			void run();

		protected:
			void init();
			void gameLoop();
			void input();
			void render();
			void update(float interval);

		private:
			void sync();
		};
	}
}