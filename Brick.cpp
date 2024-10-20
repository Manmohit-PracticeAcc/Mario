#include "Brick.h"
#include <iostream>

Brick::Brick(sf::Texture& texture, float x, float y) :
	isBouncing(false),
	bounce(false),
	breakIt(false)
{
	tile.setSize(sf::Vector2f(32, 32));
	tile.setPosition(x * 32, y * 32);

	topLeft.setTexture(texture);
	topLeft.setTextureRect(sf::IntRect(16 * 32, 6 * 32, 1 * 16, 1 * 16));
	topLeft.setPosition(x * 32, y * 32);

	topRight.setTexture(texture);
	topRight.setTextureRect(sf::IntRect(16 * 32 + 16, 6 * 32, 1 * 16, 1 * 16));
	topRight.setPosition(x * 32 + 16, y * 32);

	bottomLeft.setTexture(texture);
	bottomLeft.setTextureRect(sf::IntRect(16 * 32, 6 * 32 + 16, 1 * 16, 1 * 16));
	bottomLeft.setPosition(x * 32, y * 32 + 16);

	bottomRight.setTexture(texture);
	bottomRight.setTextureRect(sf::IntRect(16 * 32 + 16, 6 * 32 + 16, 1 * 16, 1 * 16));
	bottomRight.setPosition(x * 32 + 16, y * 32 + 16);

}

int Brick::checkRightCollision(sf::Sprite* sprite , bool isBig)
{
	int topDec = 8;
	if (!isBig) {
		topDec *= 3;
	}
	float spriteTop = sprite->getGlobalBounds().top + topDec;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height - topDec - 8;
	float spriteLeft = sprite->getGlobalBounds().left + 10;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;

	float tileTop = tile.getGlobalBounds().top + 5;
	float tileBottom = tileTop + tile.getGlobalBounds().height-10;
	float tileLeft = tile.getGlobalBounds().left;
	float tileRight = tileLeft + tile.getGlobalBounds().width;

	if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())
		&& tileLeft > spriteLeft
		&& tileRight > spriteRight
		&& tileTop < spriteBottom
		&& tileBottom > spriteTop) {
		return tileLeft;
	}
	return -1;
}

int Brick::checkLeftCollision(sf::Sprite* sprite , bool isBig)
{
	int topDec = 8;
	if (!isBig) {
		topDec *= 3;
	}
	float spriteTop = sprite->getGlobalBounds().top + topDec;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height - topDec - 8;
	float spriteLeft = sprite->getGlobalBounds().left + 10;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;

	float tileTop = tile.getGlobalBounds().top + 5;
	float tileBottom = tileTop + tile.getGlobalBounds().height-10;
	float tileLeft = tile.getGlobalBounds().left;
	float tileRight = tileLeft + tile.getGlobalBounds().width;

	if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())
		&& tileLeft < spriteLeft
		&& tileRight < spriteRight
		&& tileTop < spriteBottom
		&& tileBottom > spriteTop
		) {
		return tileRight;
	}

	return -1;
}

int Brick::checkDownCollision(sf::Sprite* sprite)
{
	float spriteTop = sprite->getGlobalBounds().top ;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height;
	float spriteLeft = sprite->getGlobalBounds().left + 10;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;

	float tileTop = tile.getGlobalBounds().top + 2;
	float tileBottom = tileTop + tile.getGlobalBounds().height;
	float tileLeft = tile.getGlobalBounds().left;
	float tileRight = tileLeft + tile.getGlobalBounds().width;
	if (tileRight > spriteLeft
		&& tileLeft < spriteRight
		&& tileTop <= spriteBottom
		&& tileTop > spriteTop
		&& tileBottom > spriteBottom
		) {
		return tileTop;
	}
	return -1;
}

int Brick::checkUpCollision(sf::Sprite* sprite , bool isBig)
{
	int topDec = 8;
	if (!isBig) {
		topDec *= 3;
	}
	float spriteTop = sprite->getGlobalBounds().top +topDec;
	float spriteBottom = spriteTop + sprite->getGlobalBounds().height - topDec - 8;
	float spriteLeft = sprite->getGlobalBounds().left + 10;
	float spriteRight = spriteLeft + sprite->getGlobalBounds().width - 20;

	float tileTop = tile.getGlobalBounds().top + tile.getGlobalBounds().height/2.0;
	float tileBottom = tileTop + tile.getGlobalBounds().height/2.0;
	float tileLeft = tile.getGlobalBounds().left;
	float tileRight = tileLeft + tile.getGlobalBounds().width;

	if (tile.getGlobalBounds().intersects(sprite->getGlobalBounds())
		&& tileBottom > spriteTop
		&& tileTop <= spriteBottom
		&& tileRight > spriteLeft
		&& tileLeft < spriteRight
		) {
		if (isBig) {
			breakIt = true;
		}
		else {
			bounce = true;
		}
		return tileBottom;
	}
	return -1;
}

void Brick::draw(sf::RenderWindow* window)
{
	if (bounce && clock.getElapsedTime().asMilliseconds() >= 100 ) {
		if (!isBouncing) {
			tile.move(0, -5);
			topLeft.move(0, -5);
			topRight.move(0, -5);
			bottomLeft.move(0, -5);
			bottomRight.move(0, -5);
			isBouncing = true;
		}
		else {
			tile.move(0, 5);
			topLeft.move(0, 5);
			topRight.move(0, 5);
			bottomLeft.move(0, 5);
			bottomRight.move(0, 5);
			isBouncing = false;
			bounce = false;
		}

		clock.restart();
	}

	if (breakIt && clock.getElapsedTime().asMilliseconds() >= 10) {

		tile.setSize(sf::Vector2f(0, 0));

		if (topLeft.getPosition().x > tile.getPosition().x - 32) {
			topLeft.move(-4, -4);
		}
		else {
			topLeft.move(-1, 10 );
		}

		if (topRight.getPosition().x < tile.getPosition().x + 48) {
			topRight.move(4, -4);
		}
		else {
			topRight.move(1, 10);
		}

		if (bottomLeft.getPosition().x > tile.getPosition().x - 32) {
			bottomLeft.move(-4, 4);
		}
		else {
			bottomLeft.move(-1, 10);
		}

		if (bottomRight.getPosition().x < tile.getPosition().x + 48) {
			bottomRight.move(4, 4);
		}
		else {
			bottomRight.move(1, 10);
		}

		topLeft.setOrigin(8,8);
		topRight.setOrigin(8, 8);
		bottomLeft.setOrigin(8, 8);
		bottomRight.setOrigin(8, 8);

		topLeft.rotate(10);
		topRight.rotate(10);
		bottomLeft.rotate(10);
		bottomRight.rotate(10);


		//if (!isBroken) {
		//	//tile.move(-5, -5);
		//	tile.setSize(sf::Vector2f(0, 0));
		//	
		//	topRight.move(5, -5);
		//	bottomLeft.move(-5, 5);
		//	bottomRight.move(5, 5);
		//	isBroken = true;
		//}
		//else {
		//	topLeft.move(0, 10);
		//	topRight.move(0, 10);
		//	bottomLeft.move(0, 10);
		//	bottomRight.move(0, 10);
		//}

		clock.restart();
	}

	window->draw(tile);
	window->draw(topLeft);
	window->draw(topRight);
	window->draw(bottomLeft);
	window->draw(bottomRight);
}
