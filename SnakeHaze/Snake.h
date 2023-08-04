#pragma once
#include "BaseSnakeItem.h"
#include "Tail.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <vector>


class Snake :public BaseSnakeItem
{
	std::vector<std::unique_ptr<Tail>> tail_objects;

	void loadTextures() override;
	void tailMove();
	void changeDirection(sf::Keyboard::Key key);
	sf::Vector2f calculateDelta(direction direct);
public:
	void addTail();
	void move() override;
	void update(sf::Keyboard::Key key);
	void draw(sf::RenderWindow& window);
	Snake(sf::Vector2f start_position, sf::Keyboard::Key key);
	Snake();
};

