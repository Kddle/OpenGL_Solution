#pragma once
#include <chrono>

namespace Kaddle {
	namespace Engine {
		class Timer
		{
		private:
			double lastLoopTime;
		public:
			void init();
			double getTime();
			float getElapsedTime();
			double getLastLoopTime();
		};
	}
}