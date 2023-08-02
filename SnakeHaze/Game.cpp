#include "Game.h"
#include "Snake.h"
#include <iostream>

Game::Game()
{
	generator.seed(rd());
	apples_ptr = nullptr;
	width_dist = std::uniform_int_distribution<>(50, window_width - 50); // Генераторы случайных чисел
	height_dist = std::uniform_int_distribution<>(50, window_height - 50);
}

void Game::start() 
{ 
	window.create(sf::VideoMode(window_height, window_width), "SnakeHaze");
	apples_ptr = std::unique_ptr<CollectableItem>( new CollectableItem(sf::Vector2f(width_dist(generator), height_dist(generator))) );
	snake = Snake(sf::Vector2f(window_width / 2, window_height / 2), sf::Keyboard::Key::Right);

	sf::RectangleShape apple_box;
	apple_box.setOutlineColor(sf::Color::Blue);
	apple_box.setOutlineThickness(2.f);
	apple_box.setSize(sf::Vector2f(apples_ptr->getGlobalBounds().width, apples_ptr->getGlobalBounds().height));
	apple_box.setPosition(apples_ptr->getPosition());

	sf::RectangleShape snake_box;
	snake_box.setFillColor(sf::Color::Yellow);
	snake_box.setOutlineColor(sf::Color::Blue);
	snake_box.setOutlineThickness(2.f);
	snake_box.setSize(sf::Vector2f(snake.getGlobalBounds().width, snake.getGlobalBounds().height));
	snake_box.setPosition(snake.getPosition());

	while (window.isOpen())
	{
		sf::Event window_event;
		while (window.pollEvent(window_event))
		{
			if (window_event.type == sf::Event::Closed)
				window.close();
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				snake.update(sf::Keyboard::Left);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				snake.update(sf::Keyboard::Right);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				snake.update(sf::Keyboard::Up);
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				snake.update(sf::Keyboard::Down);
		}
		collisionCheck();
		window.clear();
		snake.move();
		window.draw(apple_box);
		window.draw(snake_box);
		window.draw(snake);
		window.draw(*apples_ptr);
		snake_box.setPosition(snake.getPosition());
		window.display();
	}
};

void Game::collisionCheck()
{
	sf::FloatRect nextPos = snake.getGlobalBounds();
	nextPos.left += snake.getSpeed();
	nextPos.top += snake.getSpeed();
	if (apples_ptr->getGlobalBounds().intersects(nextPos))
	{
		apples_ptr.reset();
		apples_ptr = std::unique_ptr<CollectableItem>(new CollectableItem(sf::Vector2f(width_dist(generator), height_dist(generator)))); // Создаем новый объект на случайных координатах
	}
}

void Game::update()
{
	
}

/*
	apples_ptr.reset();
	apples_ptr = std::unique_ptr<CollectableItem>(new CollectableItem(sf::Vector2f(width_dist(generator), height_dist(generator)))); // Создаем новый объект на случайных координатах
*/