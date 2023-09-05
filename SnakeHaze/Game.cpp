#include "Game.h"
#include "Snake.h"
#include "Menu.h"
#include <iostream>

Game::Game()
{
	isEnd = true;
	generator.seed(rd());
	apples_ptr = nullptr;
	width_dist = std::uniform_int_distribution<>(50, window_width - 50); // Генераторы случайных чисел
	height_dist = std::uniform_int_distribution<>(50, window_height - 50);
}

void Game::start() 
{ 
	window.create(sf::VideoMode(window_width, window_height), "SnakeHaze");
	apples_ptr = std::unique_ptr<CollectableItem>( new CollectableItem(sf::Vector2f(width_dist(generator), height_dist(generator))) );
	snake = Snake(sf::Vector2f(window_width / 2, window_height / 2), sf::Keyboard::Key::Right);
	Menu menu(window_width, window_height);
	while (window.isOpen())
	{
		// Отрисовка меню и ожидание выбора
		window.clear();
		menu.draw(window);
		window.display();
		sf::Event window_event;
		while (window.pollEvent(window_event))
		{
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				menu.click(sf::Mouse::getPosition(window));
			if (menu.getState() == Menu::state::START)
			{
				isEnd = false;
				break;
			}
			if (menu.getState() == Menu::state::END)
				window.close();
		}
		while (!isEnd) // Игровой цикл
		{
			sf::Event window_event;
			while (window.pollEvent(window_event))
			{
				if (window_event.type == sf::Event::Closed)
				{
					window.close();
					isEnd = true;
					break;
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					snake.update(sf::Keyboard::Left);
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					snake.update(sf::Keyboard::Right);
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					snake.update(sf::Keyboard::Up);
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					snake.update(sf::Keyboard::Down);
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					menu.click(sf::Mouse::getPosition(window));
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					menu.changeState(Menu::state::DEFAULT);
					isEnd = true;
					break;
				}
			}

			window.clear();

			snake.move();
			collisionCheck();

			snake.draw(window);
			window.draw(*apples_ptr);

			window.display();
		}
	}
	
};

void Game::collisionCheck()
{
	if (snake.getLocation() == apples_ptr->getLocation())
	{
		if (apples_ptr->getGlobalBounds().intersects(snake.getGlobalBounds()))
		{
			snake.addTail();
			apples_ptr.reset();
			apples_ptr = std::unique_ptr<CollectableItem>(new CollectableItem(sf::Vector2f(width_dist(generator), height_dist(generator)))); // Создаем новый объект на случайных координатах
		}
	}
	if (snake.getTails().size() > 2)
	{
		sf::FloatRect next_pos = snake.getGlobalBounds();
		next_pos.left += snake.getSpeed();
		next_pos.top += snake.getSpeed();
		for (auto begin = snake.getTails().begin() + 2; begin != snake.getTails().end(); ++begin)
		{
			if ((*begin).getLocation() == snake.getLocation() && (*begin).getGlobalBounds().intersects(next_pos))
				stop();
		}
	}
}

void Game::stop()
{
	isEnd = true;
}

void Game::update()
{

}