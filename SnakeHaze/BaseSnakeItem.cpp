#include "BaseSnakeItem.h"

BaseSnakeItem::BaseSnakeItem() : speed(0.05f), direction_state(RIGHT), current_position(sf::Vector2f(0.f,0.f)) { }

BaseSnakeItem::BaseSnakeItem(sf::Vector2f start_position, direction direction)
{
	speed = 0.05;
	direction_state = direction;
	current_position = start_position;
	setPosition(start_position);
}

void BaseSnakeItem::updateTexture()
{
	setTexture(textures[direction_state], true);
}

float BaseSnakeItem::getSpeed()
{
	return speed;
}

BaseSnakeItem::direction BaseSnakeItem::getDirection()
{
	return direction_state;
}