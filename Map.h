#include <SFML/Graphics.hpp>
#include "Brick.h"
#include "Pipe.h"
#include "Floor.h"
#include "QuestionBlock.h"
#include "Stone.h"

#pragma once
class Map
{
	sf::Texture texture;
public :

	std::vector<Brick*> bricks;
	std::vector<QuestionBlock*> blocks;
	std::vector<Pipe*> pipes;
	std::vector<Floor*> floors;
	std::vector<Stone*> stones;
	Map();
	void render();
	void renderFloor();
	void renderPipes();
	void renderBricksBlocks();

	void renderStones();

	int mapEnd;

	int checkRightCollision(sf::Sprite* , bool);

	int checkLeftCollision(sf::Sprite* , bool);

	int checkDownCollision(sf::Sprite*);

	int checkUpCollision(sf::Sprite* , bool);

	bool checkPowerUp(sf::Sprite*);

	void draw(sf::RenderWindow* window , float );
};

