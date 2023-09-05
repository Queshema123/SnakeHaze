#include "Button.h"

Button::Button() { setPosition(0.f, 0.f); }

Button::Button(const std::string& t, int width, int height, float x, float y, sf::Color text_color, sf::Color button_color)
{
	if (!font.loadFromFile("Fonts//OpenSans-Bold.ttf"))
	{
		std::cout << "Can't load fonts for button";
	}
	else
	{
		text = sf::Text(t, font, width / 6);
		text.setPosition(x, y + (height / 2));
		text.setFillColor(text_color);
		setFillColor(button_color);
		setPosition(x, y);
		setSize(sf::Vector2f(width, height));
	}
}

bool Button::inBounds(const sf::Vector2i& mouse_pos)
{
	int x = static_cast<int>(getPosition().x), y = static_cast<int>(getPosition().y);
	int width = static_cast<int>(getSize().x), height = static_cast<int>(getSize().y);
	return mouse_pos.x < x + width && mouse_pos.x > x && mouse_pos.y > y && mouse_pos.y < y + height;
}