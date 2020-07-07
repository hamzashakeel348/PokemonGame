#pragma once
#include<iostream>
#include<SFML/Graphics.hpp>
using namespace std;
class button {
public:
	button() {}

	button(string te, float x, float y, int si, sf::Color bgcolor, sf::Color textclr)
	{
		text.setString(te);
		text.setFillColor(textclr);
		text.setCharacterSize(si);
		but.setSize(sf::Vector2f(x, y));
		but.setFillColor(bgcolor);
	}
	void setText(string str)
	{
		text.setString(str);
		text.setCharacterSize(str.size());
	}
	void Setsize(float x, float y)
	{
		but.setSize(sf::Vector2f(x,y));
	}
	void ScaleText(float x, float y)
	{
		text.scale(x, y);
	}
	void setFont(sf::Font& font)
	{
		text.setFont(font);
	}
	void setbcolor(sf::Color co)
	{
		but.setFillColor(co);
		but.setOutlineColor(sf::Color::White);
	}
	void settcolor(sf::Color cc)
	{
		text.setFillColor(cc);
	}
	void setpos(int x, int y)
	{
		but.setPosition(sf::Vector2f(x, y));
		float xpos = (x + but.getGlobalBounds().width / 2) - (text.getGlobalBounds().width / 2);
		float ypos = (y + but.getGlobalBounds().height / 2) - (text.getGlobalBounds().height / 2);
		text.setPosition(sf::Vector2f(xpos, ypos));
	}
	void draw(sf::RenderWindow &window)
	{
		window.draw(but);
		window.draw(text);
	}

	bool ismouse(sf::RenderWindow& win)
	{
		float mousex = sf::Mouse::getPosition(win).x;
		float mousey = sf::Mouse::getPosition(win).y;

		float btnx = but.getPosition().x;
		float btny = but.getPosition().y;

		float btnposwid = btnx + but.getGlobalBounds().width;
		float btnposhei = btny + but.getGlobalBounds().height;

		if (mousex<btnposwid && mousex > btnx && mousey<btnposhei && mousey>btny) {

			return true;
		}
		return false;

	}
private:
	sf::RectangleShape but;
	sf::Text text;
};

