#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
#include <memory>
#include <random>
#include "CollectableItem.h"
#include "Snake.h"
#include "GlobalSettings.h"

extern const int window_width;
extern const int window_height;

class Game
{
	sf::RenderWindow window;
	std::random_device rd;
	std::mt19937 generator;
	std::uniform_int_distribution<> width_dist;
	std::uniform_int_distribution<> height_dist;
	std::unique_ptr<CollectableItem> apples_ptr;
	Snake snake;
	bool isEnd;
public:
	Game();
	void start();
	void collisionCheck();
	void update();
	void stop();
};
#endif _GAME_H_