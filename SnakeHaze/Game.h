#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <random>
#include "CollectableItem.h"
#include "Snake.h"

class Game
{
	const int window_width = 800;
	const int window_height = 800;
	sf::RenderWindow window;
	std::random_device rd;
	std::mt19937 generator;
	std::uniform_int_distribution<> width_dist;
	std::uniform_int_distribution<> height_dist;
	std::unique_ptr<CollectableItem> apples_ptr;
	Snake snake;
public:
	Game();
	void start();
	void collisionCheck();
	void update();
};

/*
	std::random_device device;
	std::mt19937 rng(device());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, 9);
*/