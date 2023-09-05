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

sf::Vector2f Snake::calculateDelta(direction direct)
{// Вычисляет на основе направление куда нужно сместить хвост относительно головы/хвоста
	sf::Vector2f delta(0.f, 0.f);
	switch (direct)
	{
	case BaseSnakeItem::UP:
		delta.y = getGlobalBounds().height;
		break;
	case BaseSnakeItem::DOWN:
		delta.y = -getGlobalBounds().height;
		break;
	case BaseSnakeItem::LEFT:
		delta.x = getGlobalBounds().width;
		break;
	case BaseSnakeItem::RIGHT:
		delta.x = -getGlobalBounds().width;
		break;
	}
	return delta;
}

void Snake::loadTextures()
{
	textures[Snake::direction::UP].loadFromFile("Img\\SnakeHeadUp.png");
	textures[Snake::direction::DOWN].loadFromFile("Img\\SnakeHeadDown.png");
	textures[Snake::direction::LEFT].loadFromFile("Img\\SnakeHeadLeft.png");
	textures[Snake::direction::RIGHT].loadFromFile("Img\\SnakeHeadRight.png");
}

void Snake::addTail()
{ // current_position + delta - это позиция, на которой нужно разместить хвост относительно того, куда сейчас направляется впереди идущий элемент
	//Пример: Если голова/хвост направляется наверх, то хвост нужно разместить под ней, т.е ниже чем голова.хвост
	sf::Vector2f delta(0.f, 0.f);
	if (!tail_objects.empty())
	{
		auto current_direction = (*(tail_objects.end() - 1)).getDirection(); // Получаем направление последнего из них
		delta = calculateDelta(current_direction); // Смещение относительно направления движеня
		sf::Vector2f start_pos = (*(tail_objects.end() - 1)).getPosition(); // Получаем позицию последнего хвоста
		tail_objects.push_back(Tail(start_pos + delta, start_pos, current_direction));
	}
	else
	{
		delta = calculateDelta(direction_state);
		tail_objects.push_back(Tail(getPosition() + delta, getPosition(), direction_state));
	}
}

void Snake::tailMove()
{
	tail_objects[0].update(getPosition(), direction_state);
	tail_objects[0].move();
	if (tail_objects.size() > 1)
	{
		for (size_t i = 1; i < tail_objects.size(); i++)
		{
			tail_objects[i].update(tail_objects[i - 1].getPosition(), tail_objects[i - 1].getDirection());
			tail_objects[i].move();	
		}
	}
}

void Snake::draw(sf::RenderWindow& window)
{
	window.draw(*this);
	for (auto& tail : tail_objects)
	{
		window.draw(tail);
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
	updateLocation();
	if (tail_objects.size()>0) tailMove();
}

void Snake::update(sf::Keyboard::Key key)
{
	changeDirection(key);
	updateTexture();
}