#include <SFML/Graphics.hpp>
#pragma once
class Floor
{
	std::vector<sf::Sprite> tiles;

public: 
	Floor(sf::Texture&, float x, float y, float tilesN , bool isStrating);

	int checkDownCollision(sf::Sprite*);
	int checkRightCollision(sf::Sprite*);
	int checkLeftCollision(sf::Sprite*);
	void draw(sf::RenderWindow*window);
};

