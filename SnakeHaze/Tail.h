#pragma once
#include "BaseSnakeItem.h"
#include <queue>
#include <utility>

class Tail : public BaseSnakeItem
{
private:
	std::queue<std::pair<sf::Vector2f, direction>> next_direction_state;
	bool isReachedPosition();
	void loadTextures() override;
public:
	Tail(sf::Vector2f start_position, direction direction);
	void move() override;
	void update(sf::Vector2f position, direction direction);
	~Tail() = default;
};

