#include "Tail.h"

Tail::Tail(sf::Vector2f start_position, direction direction) : BaseSnakeItem(start_position, direction)
{
	loadTextures();
}

void Tail::loadTextures()
{
	textures[Tail::direction::UP].loadFromFile("Img\\SnakeTailUp.png");
	textures[Tail::direction::DOWN].loadFromFile("Img\\SnakeTailDown.png");
	textures[Tail::direction::LEFT].loadFromFile("Img\\SnakeTailLeft.png");
	textures[Tail::direction::RIGHT].loadFromFile("Img\\SnakeTailRight.png");
}

bool Tail::isReachedPosition()
{ // ƒостиг ли хвост той позиции, где была повернута голова
	return current_position == next_direction_state.front().first;
}

void Tail::update(sf::Vector2f position, direction direction)
{
	next_direction_state.push(std::make_pair(position, direction)); // ƒобавление новой пары позици€-направление
	if (isReachedPosition()) //≈сли достигли нужной позиции 
	{
		updateTexture();
		next_direction_state.pop();
	}
}

void Tail::move()
{
	switch (next_direction_state.front().second)
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
}
