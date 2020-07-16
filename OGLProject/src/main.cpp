#include "Game.h"
int main()
{
	Game game("SpidermanPizzaTime",
		640, 480,
		false);

	while (!game.getWindowShouldClose())
	{
		game.update();
		game.render();
	}

	return 0;
}