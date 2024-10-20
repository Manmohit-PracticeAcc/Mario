#include <SFML/Graphics.hpp>
#pragma once
class Pipe
{
	std::vector<sf::Sprite > tiles;
public:
	Pipe(sf::Texture& texture, int size, float x, float y);
	void draw(sf::RenderWindow *window);

	int checkRightCollision(sf::Sprite*);

	int checkLeftCollision(sf::Sprite*);

	int checkDownCollision(sf::Sprite*);
};


