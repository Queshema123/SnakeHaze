#ifndef _BASE_SNAKE_ITEM_H_
#define _BASE_SNAKE_ITEM_H_
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
	enum location { TOP_LEFT, TOP_RIGHT, DOWN_LEFT, DOWN_RIGHT, CENTER } current_location;
	std::map<BaseSnakeItem::direction, sf::Texture> textures; // Текстуры, нужны для корретного отображения при смене передвижения
	void updateTexture();
	virtual void loadTextures() = 0;
public:
	BaseSnakeItem();
	BaseSnakeItem(sf::Vector2f start_position, direction direction);
	float getSpeed() const { return speed; }
	void updateLocation();
	location getLocation() const { return current_location; }
	direction getDirection() const { return direction_state; }
	virtual void move() = 0;
	virtual ~BaseSnakeItem() = default;
};
#endif _BASE_SNAKE_ITEM_H_