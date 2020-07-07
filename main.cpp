#include <iostream>
#include "Game.h"
#include "win.h"
#include <sfml/Graphics.hpp>


using namespace sf;
using namespace std;



int main()
{

	Game game; // Creating our game object.
	
	while (1)
	{
		game.HandleInput();
		game.Update();
		game.Render();
	}
	
}
