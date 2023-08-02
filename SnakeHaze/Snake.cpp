#include "Snake.h"

Snake::Snake() { }

Snake::Snake(sf::Vector2f start_position, sf::Keyboard::Key key) : BaseSnakeItem(start_position, static_cast<direction>(key))
{
	loadTextures();
	updateTexture();
}

void Snake::changeDirection(sf::Keyboard::Key key)
{
	switch (key)
	{
	case BaseSnakeItem::direction::UP:
		direction_state = UP;
		break;
	case BaseSnakeItem::direction::DOWN:
		direction_state = DOWN;
		break;
	case BaseSnakeItem::direction::RIGHT:
		direction_state = RIGHT;
		break;
	case BaseSnakeItem::direction::LEFT:
		direction_state = LEFT;
		break;
	default:
		break;
	}
}

void Snake::loadTextures()
{
	textures[Snake::direction::UP].loadFromFile("Img\\SnakeHeadUp.png");
	textures[Snake::direction::DOWN].loadFromFile("Img\\SnakeHeadDown.png");
	textures[Snake::direction::LEFT].loadFromFile("Img\\SnakeHeadLeft.png");
	textures[Snake::direction::RIGHT].loadFromFile("Img\\SnakeHeadRight.png");
}

void Snake::addTail()
{
	tail_objects.push_back(std::make_unique<Tail>(current_position, direction_state));
}

void Snake::tail_move()
{
	for (auto& tail : tail_objects)
	{
		tail->update(getPosition(), direction_state);
	}
}

void Snake::move()
{
	switch (direction_state)
	{
	case direction::UP:
		current_position.y -= speed;
		break;
	case direction::DOWN:
		current_position.y += speed;
		break;
	case direction::LEFT:
		current_position.x -= speed;
		break;
	case direction::RIGHT:
		current_position.x += speed;
		break;
	}
	setPosition(current_position);
	tail_move();
}

void Snake::update(sf::Keyboard::Key key)
{
	changeDirection(key);
	updateTexture();
}