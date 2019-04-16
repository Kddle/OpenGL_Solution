#pragma once
#include "../engine/GameLogic.h"
#include "../engine/Window.h"
#include "Renderer.h"

namespace Kaddle {
	namespace Game {
		class HelloGame : public Kaddle::Engine::GameLogic
		{
		private:
			int direction;
			float color;
			Kaddle::Game::Renderer renderer;

		public:
			HelloGame();
			void init();
			void input(Kaddle::Engine::Window* window);
			void update(float interval);
			void render(Kaddle::Engine::Window* window);
		};
	}
}