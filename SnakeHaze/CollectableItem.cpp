#include "CollectableItem.h"

CollectableItem::CollectableItem(sf::Vector2f position)
{
	texture.loadFromFile("Img\\CollectableItem.png");
	setTexture(texture);
	setPosition(position);
}
