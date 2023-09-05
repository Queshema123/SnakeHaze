#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "BaseSnakeItem.h"
#include "Tail.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>

class Snake :public BaseSnakeItem
{
	std::vector<Tail> tail_objects;

	void loadTextures() override;
	void tailMove();
	void changeDirection(sf::Keyboard::Key key);
	sf::Vector2f calculateDelta(direction direct);
public:
	void addTail();
	void move() override;
	void update(sf::Keyboard::Key key);
	void draw(sf::RenderWindow& window);
	const std::vector<Tail>& getTails() { return tail_objects; }
	Snake(sf::Vector2f start_position, sf::Keyboard::Key key);
	Snake();
};
#endif _SNAKE_H_