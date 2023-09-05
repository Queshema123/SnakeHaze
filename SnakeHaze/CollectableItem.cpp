#include "CollectableItem.h"
#include "GlobalSettings.h"

extern const int window_height;
extern const int window_width;

CollectableItem::CollectableItem(sf::Vector2f position)
{
	texture.loadFromFile("Img\\CollectableItem.png");
	setTexture(texture);
	setPosition(position);
	int half_width = window_width / 2, half_height = window_height / 2;
	if (position.x <= half_width && position.y <= half_height) current_location = TOP_LEFT;
	if (position.x >= half_width && position.y <= half_height) current_location = TOP_RIGHT;
	if (position.x >= half_width && position.y >= half_height) current_location = DOWN_RIGHT;
	if (position.x <= half_width && position.y >= half_height) current_location = DOWN_LEFT;
}
