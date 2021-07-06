//This file is part of Mactangle.
//
//Mactangle is free software : you can redistribute it and /or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//Mactangle is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with Mactangle. If not, see < https://www.gnu.org/licenses/>.

#include <iostream>
#include "TextureContainer.h"
#include "Game.h"
#include "Path.h"

int main()
{
	TextureContainer textureContainer;

	textureContainer.addPath(BACKGROUND_PNG);
    Path path;
    
    // Create the main window
    Game game;

    textureContainer.fitToVector(game.getSize());
    sf::Sprite sprite = textureContainer.getSprite();
    
    // Start the game loop
    while (game.isOpen())
    {
        // Process events
        sf::Event event;
        while (game.pollEvent(event))
        {
            // Close window: exit
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                game.close();

            // Close window: exit
            if (event.type == sf::Event::Closed)
                game.close();
        }

        // Clear screen
        game.clear();

        // Draw the sprite
        game.draw(sprite);

        // Update the window
        game.display();
    }

	return 0;
}