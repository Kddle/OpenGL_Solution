#include "Window.h"

class GameLogic
{
public:
	virtual void init();
	virtual void input(Window* window);
	virtual void update(float interval);
	virtual void render(Window* window);
};