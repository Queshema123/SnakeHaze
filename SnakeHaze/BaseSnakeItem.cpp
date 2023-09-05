#include "BaseSnakeItem.h"
#include "GlobalSettings.h"

extern const int window_height;
extern const int window_width;

BaseSnakeItem::BaseSnakeItem() : speed(0.05f), direction_state(RIGHT), current_position(sf::Vector2f(0.f,0.f)), current_location(CENTER) { }

BaseSnakeItem::BaseSnakeItem(sf::Vector2f start_position, direction direction)
{
	speed = 0.05;
	direction_state = direction;
	current_position = start_position;
	setPosition(start_position);
	updateLocation();
}

void BaseSnakeItem::updateLocation()
{
	sf::Vector2f pos = getPosition();
	int half_width = window_width / 2, half_height = window_height / 2;
	if (pos.x <= half_width && pos.y <= half_height) current_location = TOP_LEFT;
	if (pos.x >= half_width && pos.y <= half_height) current_location = TOP_RIGHT;
	if (pos.x >= half_width && pos.y >= half_height) current_location = DOWN_RIGHT;
	if (pos.x <= half_width && pos.y >= half_height) current_location = DOWN_LEFT;
}

void BaseSnakeItem::updateTexture()
{
	setTexture(textures[direction_state], true);
}