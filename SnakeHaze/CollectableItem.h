#ifndef _COLLECTABLE_ITEM_H_
#define _COLLECTABLE_ITEM_H_
#include<SFML/Graphics.hpp>

class CollectableItem : public sf::Sprite
{
	sf::Texture texture;
	enum location { TOP_LEFT, TOP_RIGHT, DOWN_LEFT, DOWN_RIGHT } current_location;
public:
	CollectableItem(sf::Vector2f position);
	location getLocation() { return current_location; }
};

#endif _COLLECTABLE_ITEM_H_