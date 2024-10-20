#include "Map.h"
#include <SFML/Graphics.hpp>
#include "Brick.h"
#include "QuestionBlock.h"
#include <iostream>

Map::Map()
{
	texture.loadFromFile("./Assets/Map/tilesheet.png");
}

void Map::render()
{
	renderFloor();

	renderPipes();

	renderBricksBlocks();

	renderStones();
}

void Map::renderFloor()
{
	int x = 0;
	{
		Floor* floor = new Floor(texture, 0, 22, 66, true);
		floors.push_back(floor);
	}
	{
		Floor* floor = new Floor(texture, 69, 22, 84 - 69, false);
		floors.push_back(floor);
	}

	{
		Floor* floor = new Floor(texture, 87, 22, 190 - 87, false);
		floors.push_back(floor);
		mapEnd = 190;
	}
}

void Map::renderPipes()
{
	{
		Pipe* pipe = new Pipe(texture, 2, 20, 21);
		pipes.push_back(pipe);
	}

	{
		Pipe* pipe = new Pipe(texture, 3, 34, 20);
		pipes.push_back(pipe);
	}
	{
		Pipe* pipe = new Pipe(texture, 4, 42, 19);
		pipes.push_back(pipe);
	}
	{
		Pipe* pipe = new Pipe(texture, 4, 53, 19);
		pipes.push_back(pipe);
	}
	{
		Pipe* pipe = new Pipe(texture, 3, 126, 20);
		pipes.push_back(pipe);
	}
}

void Map::renderBricksBlocks()
{

	{
		{
			Brick* brick = new Brick(texture, 13, 19);
			bricks.push_back(brick);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 14, 19, true);
			blocks.push_back(block);
		}
		{
			Brick* brick = new Brick(texture, 15, 19);
			bricks.push_back(brick);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 16, 19, false);
			blocks.push_back(block);
		}
		{
			Brick* brick = new Brick(texture, 17, 19);
			bricks.push_back(brick);
		}
	}

	{

		{
			Brick* brick = new Brick(texture, 14, 15);
			bricks.push_back(brick);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 15, 15, false);
			blocks.push_back(block);
		}
		{
			Brick* brick = new Brick(texture, 16, 15);
			bricks.push_back(brick);
		}
	}

	{
		{
			Brick* brick = new Brick(texture, 75, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 76, 19);
			bricks.push_back(brick);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 77, 19, false);
			blocks.push_back(block);
		}
		{
			Brick* brick = new Brick(texture, 78, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 79, 19);
			bricks.push_back(brick);
		}
	}

	{

		{
			Brick* brick = new Brick(texture, 79, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 80, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 81, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 82, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 83, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 84, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 85, 15);
			bricks.push_back(brick);
		}
	}

	{
		{
			Brick* brick = new Brick(texture, 88, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 89, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 90, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 91, 15);
			bricks.push_back(brick);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 92, 15, false);
			blocks.push_back(block);
		}
	}

	{
		Brick* brick = new Brick(texture, 92, 19);
		bricks.push_back(brick);
	}

	{
		{
			QuestionBlock* block = new QuestionBlock(texture, 98, 19, false);
			blocks.push_back(block);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 101, 19, false);
			blocks.push_back(block);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 101, 15, true);
			blocks.push_back(block);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 104, 19, false);
			blocks.push_back(block);
		}
	}

	{
		{
			Brick* brick = new Brick(texture, 109, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 110, 19);
			bricks.push_back(brick);
		}
	}

	{
		{
			Brick* brick = new Brick(texture, 112, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 113, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 114, 15);
			bricks.push_back(brick);
		}
	}

	{
		{
			Brick* brick = new Brick(texture, 118, 15);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 119, 15);
			bricks.push_back(brick);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 120, 15, false);
			blocks.push_back(block);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 121, 15, false);
			blocks.push_back(block);
		}
		{
			Brick* brick = new Brick(texture, 122, 15);
			bricks.push_back(brick);
		}
	}

	{
		{
			Brick* brick = new Brick(texture, 119, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 120, 19);
			bricks.push_back(brick);
		}
	}

	{
		{
			Brick* brick = new Brick(texture, 135, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 136, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 137, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 138, 19);
			bricks.push_back(brick);
		}
		{
			QuestionBlock* block = new QuestionBlock(texture, 139, 19, false);
			blocks.push_back(block);
		}
		{
			Brick* brick = new Brick(texture, 140, 19);
			bricks.push_back(brick);
		}
		{
			Brick* brick = new Brick(texture, 141, 19);
			bricks.push_back(brick);
		}
	}
}

void Map::renderStones()
{
	for (int i = 0; i < 13; i++) {
		Stone* stone = new Stone(texture, 154+i, 22-i, 13-i);
		stones.push_back(stone);
	}
}

int Map::checkRightCollision(sf::Sprite* sprite, bool isBig)
{
	for (Pipe* pipe : pipes) {
		int res = pipe->checkRightCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	for (Brick* brick : bricks) {
		int res = brick->checkRightCollision(sprite, isBig);
		if (res > -1) {
			return res;
		}
	}

	for (QuestionBlock* block : blocks) {
		int res = block->checkRightCollision(sprite, isBig);
		if (res > -1) {
			return res;
		}
	}

	for (Stone* stone : stones) {
		int res = stone->checkRightCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	return -1;
}

int Map::checkLeftCollision(sf::Sprite* sprite, bool isBig)
{
	for (Pipe* pipe : pipes) {
		int res = pipe->checkLeftCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	for (Brick* brick : bricks) {
		int res = brick->checkLeftCollision(sprite, isBig);
		if (res > -1) {
			return res;
		}
	}

	for (QuestionBlock* block : blocks) {
		int res = block->checkLeftCollision(sprite, isBig);
		if (res > -1) {
			return res;
		}
	}

	for (Stone* stone : stones) {
		int res = stone->checkLeftCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	return -1;
}

int Map::checkDownCollision(sf::Sprite* sprite)
{
	for (Pipe* pipe : pipes) {
		int res = pipe->checkDownCollision(sprite);
		if (res > -1) {
			return res;
		}
	}
	for (Floor* floor : floors) {
		int res = floor->checkDownCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	for (QuestionBlock* block : blocks) {
		int res = block->checkDownCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	for (Brick* brick : bricks) {
		int res = brick->checkDownCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	for (Stone* stone : stones) {
		int res = stone->checkDownCollision(sprite);
		if (res > -1) {
			return res;
		}
	}

	return -1;
}

int Map::checkUpCollision(sf::Sprite* sprite, bool isBig)
{
	for (QuestionBlock* block : blocks) {
		int res = block->checkUpCollision(sprite, isBig);

		if (res > -1) {
			return res;
		}
	}

	for (Brick* brick : bricks) {
		int res = brick->checkUpCollision(sprite, isBig);

		if (res > -1) {
			return res;
		}
	}
	return -1;
}

bool Map::checkPowerUp(sf::Sprite* sprite)
{
	for (QuestionBlock* block : blocks) {
		if (block->checkPowerUp(sprite)) {
			return true;
		}
	}
	return false;
}

void Map::draw(sf::RenderWindow* window, float delta)
{
	for (Floor* tile : floors) {
		tile->draw(window);
	}

	for (Pipe* pipe : pipes)
	{
		pipe->draw(window);
	}

	for (QuestionBlock* block : blocks) {
		block->draw(window, delta, this);
	}

	for (Brick* brick : bricks)
	{
		brick->draw(window);
	}

	for (Stone* stone : stones)
	{
		stone->draw(window);
	}
}

