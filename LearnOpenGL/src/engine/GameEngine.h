#include <thread>
#include "Window.h"
#include "GameLogic.h";

class GameEngine
{
public:
	static const int TARGET_FPS = 75;
	static const int TARGET_UPS = 30;
private:
	Window window;
	std::thread* gameLoopThread;
	GameLogic* gameLogic;

public:
	GameEngine(const char* windowTitle, int width, int height, bool vSync, GameLogic* gameLogic);
	void start();
	void run();

protected:
	void init();
	void gameLoop();
	void input();
	void update();
	void render();

private:
	void sync();
};