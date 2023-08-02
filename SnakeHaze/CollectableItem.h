#pragma once
#include<SFML/Graphics.hpp>

class CollectableItem : public sf::Sprite
{
	sf::Texture texture;
public:
	CollectableItem(sf::Vector2f position);
};