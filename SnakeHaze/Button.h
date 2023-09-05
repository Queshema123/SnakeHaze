#ifndef _BUTTON_H_
#define _BUTTON_H_
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
class Button : public sf::RectangleShape
{
	sf::Text text;
	sf::Font font;
public:
	Button();
	Button(const std::string& t, int width, int height, float x, float y, sf::Color text_color = sf::Color::Black, sf::Color button_color = sf::Color::White);
	bool inBounds(const sf::Vector2i& mouse_pos);
	void draw(sf::RenderWindow& window);
};

void inline Button::draw(sf::RenderWindow& window)
{
	window.draw(*this);
	window.draw(text);
}
#endif _BUTTON_H_