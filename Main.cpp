#include <iostream>
#include <SFML/Graphics.hpp>
#include "Map.h"
#include "Player.h"

using namespace sf;
int main()
{
	/* ========================== Widow creation =================================*/

	int height = 32 * 25;
	int width = int(16.0 / 9.0 * height);

	sf::RenderWindow window(sf::VideoMode(width, height), "Mario ", sf::Style::Close);

	// Setting icon to window title-bar :
	sf::Image icon;
	if (icon.loadFromFile("./Assets/Icon/logo-0.png")) {  // Replace "icon.png" with the path to your icon file
		window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
	}

	window.setVerticalSyncEnabled(true); // enabling vSync

	/*====================== Map ====================================*/
	Map map;
	sf::View view;
	view.setCenter(sf::Vector2f(width / 2, height / 2));
	view.setSize(sf::Vector2f(width, height));

	// Setting background sky :
	sf::Texture bgTexture;
	sf::Sprite background;

	if (bgTexture.loadFromFile("./Assets/Map/sky.jpg")) {
		background.setTexture(bgTexture);
		background.scale(
			float(width) / 3235,
			float(height) / 2160
		);
	}

	/*====================== Player ====================================*/
	Texture spriteSheet;
	spriteSheet.loadFromFile("./Assets/Characters/SpriteSheet-32x64.png");
	Player player(spriteSheet, 21 * 32);

	sf::Clock clock;
	map.render();
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	bool isSpacePressed = false;

	/*========================== Game Loop =================================*/
	while (window.isOpen())
	{
		background.setPosition(view.getCenter().x - (width / 2.0), view.getCenter().y - (height / 2.0));

		float delta = clock.restart().asSeconds();
		/*------------------ Event Loop -------------------*/
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		bool isMoving = false;

		/*------------------ Player Movements -------------------*/
		// Keyboard Movements :
		{
			if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
			{
				player.moveRight(delta); // Right
				isMoving = true;
			}

			if (Keyboard::isKeyPressed(Keyboard::A) || Keyboard::isKeyPressed(Keyboard::Left))
			{
				player.moveLeft(delta); // Left
				isMoving = true;
			}

			if (Keyboard::isKeyPressed(Keyboard::Space)) {
				if (!isSpacePressed) {
					player.jump(delta);
				}
				isSpacePressed = true;
			}
			else {
				isSpacePressed = false;
			}
		}

		//Up Collision :
		{
			int res = map.checkUpCollision(player.getSprite(), player.isBig);
			if (res > -1) {
				player.getSprite()->setPosition(player.getSprite()->getPosition().x, res);
				player.canMoveUp = false;
			}
			else {
				player.canMoveUp = true;
			}
		}

		// Down Collision : 
		{
			int res = map.checkDownCollision(player.getSprite());

			if (res > -1) {
				//std:: cout << resDown << std::endl; 
				player.getSprite()->setPosition(player.getSprite()->getPosition().x, res - 64);
				player.canMoveDown = false;
			}
			else {
				player.canMoveDown = true;
			}
		}

		// Right Collision :
		{
			int res = map.checkRightCollision(player.getSprite() , player.isBig);
			if (res > -1) {
				player.getSprite()->setPosition(res - 32, player.getSprite()->getPosition().y);
				player.canMoveRight = false;
				isMoving = false;
			}
			else
			{
				player.canMoveRight = true;
			}
		}

		// Left Collision :
		{
			int res = map.checkLeftCollision(player.getSprite() , player.isBig);
			if (res > -1) {
				player.getSprite()->setPosition(res, player.getSprite()->getPosition().y);
				player.canMoveLeft = false;
				isMoving = false;
			}
			else
			{
				player.canMoveLeft = true;
			}

			// Collision with window view 
			if (view.getCenter().x - (width / 2.0) + 32 >= player.getSprite()->getPosition().x) {
				player.canMoveLeft = false;
			}
			else {
				player.canMoveLeft = true;
			}
		}

		if (map.checkPowerUp(player.getSprite())) {
			player.Upgrade();
		}

		player.move(delta, isMoving, &view, map.mapEnd);
		player.applyGravity(delta);

		/*------------------ Drawing stuff -------------------*/

		window.clear();
		window.setView(view);

		window.draw(background);
		map.draw(&window, delta);
		player.draw(&window);
		window.display();
	}

	return 0;
}
