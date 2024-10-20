#include "Player.h"
#include <iostream>

Player::Player(sf::Texture& texture, float floor) :
	col(0),
	row(0),
	spriteWidth(32),
	spriteHeight(64),
	isMovingLeft(false),
	canMoveLeft(true),
	canMoveRight(true),
	speedX(0),
	isBig(false),
	gravity(800),
	speedY(0),
	floor(floor),
	canMoveUp(true),
	canMoveDown(true)
{
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(col * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));
	sprite.setPosition(100, floor);
}

sf::Sprite* Player::getSprite()
{
	return &sprite;
}

void Player::moveRight(float delta)
{
	if (speedX < 150 && canMoveRight) speedX += 300 * delta;
	if(!canMoveRight) speedX = 0;
}

void Player::moveLeft(float delta)
{
	if (speedX > -150 && canMoveLeft) speedX -= 300 * delta;
	if (!canMoveLeft) speedX = 0;
}

void Player::move(float delta, bool isMoving , sf::View* view , int mapEnd)
{
	sprite.move(speedX * delta, 0);
	if (
		sprite.getPosition().x >= view->getCenter().x
		&& view->getCenter().x + (view->getSize().x / 2.0) < mapEnd * 32
		) {
		if (sprite.getPosition().x > view->getCenter().x) {
			int move = sprite.getPosition().x - view->getCenter().x;
			view->setCenter(view->getCenter().x + move * delta, view->getCenter().y);
		}
		else view->setCenter(view->getCenter().x + speedX * delta, view->getCenter().y);
	}

	if (!isMoving)
	{
		//Applying friction
		if (speedX > 0) speedX -= 200 * delta;
		if (speedX < 0) speedX += 200 * delta;
		if (speedX > -10 && speedX < 10) speedX = 0;
	}

	if (speedX > 15) {
		// Moving right
		row = isMovingLeft ? row - 1 : row;
		col = (col + 1) % 2;
		if (spriteClock.getElapsedTime().asMilliseconds() > 100) {
			sprite.setTextureRect(sf::IntRect(col * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));
			spriteClock.restart();
		}
		isMovingLeft = false;
	}

	else if (speedX < -15) {
		// Moving left
		row = isMovingLeft ? row : row + 1;
		col = (col + 1) % 2;
		if (spriteClock.getElapsedTime().asMilliseconds() > 100) {
			sprite.setTextureRect(sf::IntRect(col * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));
			spriteClock.restart();
		}
		isMovingLeft = true;
	}
	else{
		col = 0;
		sprite.setTextureRect(sf::IntRect(col * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));
	}
}

void Player::jump(float delta)
{
	if (!canMoveDown) {
		speedY = -500; // Set initial jump velocity
		sprite.move(0,speedY*delta);
		canMoveDown = true;
	}
}

void Player::applyGravity(float delta)
{
	if (!canMoveUp) {
		speedY = 100;
	}
	if (canMoveDown) {
		speedY += gravity * delta ; // Update vertical velocity with gravity
		sprite.move(0, speedY * delta); // Move the sprite based on vertical velocity
		sprite.setTextureRect(sf::IntRect(2 * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));
	}
}

void Player::Upgrade()
{
	if (!isBig) {
		row = row + 2;
		sprite.setTextureRect(sf::IntRect(0 * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));
		isBig = true;

	}
}

void Player::Downgrade()
{
	if (isBig) {
		row = row - 2;
		sprite.setTextureRect(sf::IntRect(0 * spriteWidth, row * spriteHeight, spriteWidth, spriteHeight));
		isBig = false;

	}
}


void Player::draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}
