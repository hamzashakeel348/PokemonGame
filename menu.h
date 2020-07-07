#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <windows.h>
#include <cmath>
#include"char.h"
#include"BAG.h"
#include"pokdex.h"
#include<SFML/Graphics.hpp>
class menu
{
	pokedex e;
	BAG l;
	char_team c;
public:
	void men(sf::RenderWindow& window)
	{
		sf::Text text;
		sf::Text text2;
		sf::Text text3;
		sf::Font ar;
		ar.loadFromFile("arial.ttf");
		text2.setFont(ar);
		text3.setFont(ar);
		string m;
		m = " Press A: For Pokedex \n Press B: For Pokemon \n Press C: For Bag Items \n Press S: To Save the Game \n Press Esc: To Quit";
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
					window.close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{
					string a = "Welcome to Pokedex";
					sf::Text t1;
					t1.setString(a);
					t1.setFont(ar);
					t1.setCharacterSize(40);
					t1.setPosition(sf::Vector2f(50, 50));
					window.clear();
					window.draw(t1);
					window.display();
					e.main2(window);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B))
				{
					c.draw(window);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
				{
					l.set(window);
				}
			}


			text2.setString("Welcome To MENU");
			text2.setFillColor(sf::Color::Cyan);
			text2.setOutlineColor(sf::Color::Green);
			text2.setPosition(100, 130);
			text3.setPosition(190, 250);
			text2.setCharacterSize(70);
			text3.setString(m);
			text3.setFillColor(sf::Color::Cyan);
			window.clear(sf::Color::Black);
			window.draw(text2);
			window.draw(text3);
			window.display();
			 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					break;
				}
		}
	}
};