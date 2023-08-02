#pragma once
#include "BaseSnakeItem.h"
#include "Tail.h"
#include <memory>
#include <vector>


class Snake :public BaseSnakeItem
{
	std::vector<std::unique_ptr<Tail>> tail_objects;

	void loadTextures() override;
	void tail_move();
	void changeDirection(sf::Keyboard::Key key);
public:
	void addTail();
	void move() override;
	void update(sf::Keyboard::Key key);
	Snake(sf::Vector2f start_position, sf::Keyboard::Key key);
	Snake();
};

