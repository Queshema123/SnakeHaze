#include "Tail.h"
#include <cmath>

Tail::Tail(sf::Vector2f start_position, sf::Vector2f go_to_position, direction direction) : BaseSnakeItem(start_position, direction)
{
	loadTextures();
	updateTexture();
	next_direction_state.push(std::make_pair(go_to_position, direction));
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
	sf::Vector2f go_to_position = next_direction_state.front().first;
	return std::fabs(go_to_position.x - current_position.x) < 0.3 && std::fabs(go_to_position.y - current_position.y) < 0.3	;
}

void Tail::update(sf::Vector2f position, direction direction)
{
	next_direction_state.push(std::make_pair(position, direction)); // ƒобавление новой пары позици€-направление
}

void Tail::move()
{ 
	direction_state = next_direction_state.front().second;
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
	if (isReachedPosition()) //≈сли достигли нужной позиции 
	{
		updateTexture();
		next_direction_state.pop();
	}
}

/*
	float round_go_to_position_x = std::round(go_to_position.x * 100) / 100, round_go_to_position_y = std::round(go_to_position.y * 100) / 100;
	float round_current_position_x = std::round(current_position.x * 100) / 100, round_current_position_y = std::round(current_position.y * 100) / 100;
*/