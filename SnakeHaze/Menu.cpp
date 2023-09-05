#include "Menu.h"

Menu::Menu(const int width, const int height) : start("start", width/8,height/8,width/2, height/2-120, sf::Color::Blue, sf::Color::Green), 
	options("options", width / 8, height / 8, width / 2, height / 2, sf::Color::Blue, sf::Color::Green),
	end("exit", width / 8, height / 8, width / 2, height / 2 + 120, sf::Color::Blue, sf::Color::Green),
	_state(Menu::state::DEFAULT)
{

}

void Menu::draw(sf::RenderWindow& window)
{
	switch (_state)
	{
	case Menu::state::DEFAULT:
		start.draw(window);
		options.draw(window);
		end.draw(window);
		break;
	case Menu::state::OPTIONS:
		//window.draw();
		break;
	default:
		break;
	}
	
}

void Menu::click(const sf::Vector2i& pos)
{
	if (start.inBounds(pos))
	{
		_state = Menu::state::START;
	}
	else if (options.inBounds(pos))
	{
		_state = Menu::state::OPTIONS;
	}
	else if (end.inBounds(pos))
	{
		_state = Menu::state::END;
	}
}