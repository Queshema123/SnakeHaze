#pragma once
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <map>

class BaseSnakeItem : public sf::Sprite
{ // Базовый класс для Snake и Tail
protected:
	float speed;
	sf::Vector2f current_position;
	enum direction {
		UP = sf::Keyboard::Up,
		DOWN = sf::Keyboard::Down,
		LEFT = sf::Keyboard::Left,
		RIGHT = sf::Keyboard::Right,
	}direction_state;
	std::map<BaseSnakeItem::direction, sf::Texture> textures; // Текстуры, нужны для корретного отображения при смене передвижения
	void updateTexture();
	virtual void loadTextures() = 0;
public:
	BaseSnakeItem();
	BaseSnakeItem(sf::Vector2f start_position, direction direction);
	float getSpeed();
	direction getDirection();
	virtual void move() = 0;
	virtual ~BaseSnakeItem() = default;
};

