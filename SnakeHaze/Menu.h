#ifndef _MENU_H_
#define _MENU_H_
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Menu.h"
#include "Button.h"

class Menu
{
public:
	static enum class state { DEFAULT, START, OPTIONS, END };
private:
	Button start, end, options;
	state _state;
public:
	Menu(const int width, const int height);
	void draw(sf::RenderWindow& window);
	void click(const sf::Vector2i& pos);
	state getState() const { return _state; }
	void changeState(state s) { _state = s; }
};
#endif _MENU_H_