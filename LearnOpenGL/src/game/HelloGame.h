#include "../engine/GameLogic.h"
#include "Renderer.h"

class HelloGame : public GameLogic
{
private:
	int direction;
	float color;
	Renderer renderer;

public:
	HelloGame();
	void init();
	void input(Window* window);
	void update(float interval);
	void render(Window* window);
};