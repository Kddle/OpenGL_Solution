#pragma once
#include "Window.h"

namespace Kaddle {
	namespace Engine {
		class GameLogic
		{
		public:
			virtual void init();
			virtual void input(Window* window);
			virtual void update(float interval);
			virtual void render(Window* window);
		};
	}
}