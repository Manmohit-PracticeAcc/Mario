#include <SFML/Graphics.hpp>
#pragma once
class Player
{
	int col;
	int row;
	int spriteWidth;
	int spriteHeight;
	sf::Clock spriteClock;

	sf::Sprite sprite;
	int speedX;  // Horizontal speed
	int speedY;  // Vertical speed
	float gravity;     // Gravity force
	float floor ; // Y position of the ground
	bool isMovingLeft;
public:
	bool isBig;
	bool canMoveLeft;
	bool canMoveRight;
	bool canMoveUp;
	bool canMoveDown;
	bool atCenter;
	Player(sf::Texture& texture, float floor);
	sf::Sprite* getSprite();
	void moveRight(float);
	void moveLeft(float);
	void move(float , bool , sf::View* , int);
	void jump(float);
	void applyGravity(float);
	void Upgrade();
	void Downgrade();
	void draw(sf::RenderWindow* window);
};

