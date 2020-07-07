#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cmath>
#include "RB.h"
#include<SFML/Graphics.hpp>
#include "Pokemon.h"
#include"textbox.h"
#include<vector>
 
using namespace std;

class pokedex
{
	sf::Font ar;
	sf::Text text1;
	sf::Text text2;
	sf::Text text3;
	sf::Text text4;
	sf::Text text5;
	string b;
	RBTree <int, Pokemon> A;
	Pokemon ptemp;

public:

	void insertfunc(int a, Pokemon X)
	{
		A.Insert(a, X);
	}

	Pokemon* find(int a)
	{
		return A.Find(a);
	}
	Pokemon* find(string a)
	{
		int P = stoi(a);
		return A.Find(P);
	}
	void initialize()
	{
		
		ifstream fin;
		fin.open("pokedex.txt");
		while (!fin.eof())
		{
			fin >> ptemp.id;
			fin >> ptemp.name;
			A.Insert(ptemp.id, ptemp);
		}
	}
	void Evolve(Pokemon Y, sf::RenderWindow& window)
	{
		//	window.clear();
		bool f = false;
		string s3 = " IS EVOLVING INTO ";
		ar.loadFromFile("arial.ttf");
		text4.setFont(ar);
		text3.setFont(ar);
		text5.setFont(ar);
		text1.setFont(ar);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
					window.close();
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					//window.clear(sf::Color::Black);
					break;
				}
			}
			if (find(Y.id + 1) != nullptr)
			{
				string s = Y.name;
				text1.setString(s);
				string h = find(Y.id + 1)->name;
				text4.setString(h);
				text1.setPosition(sf::Vector2f(20, 0));
				window.draw(text1);
				text1.setPosition(sf::Vector2f(10, 50));
				text4.setPosition(sf::Vector2f(450, 50));
				text5.setString(s3);
				text5.setPosition(sf::Vector2f(170, 50));
				window.draw(text5);
				window.draw(text4);

				window.draw(text1);
				window.display();
				f = true;
			}
			else
			{
				text1.setPosition(sf::Vector2f(0, 0));
				string s = Y.name;
				text1.setString(s);
				string a = "NO EVOLUTION EXISTS";
				text3.setString(a);
				text3.setPosition(sf::Vector2f(10, 50));
				window.draw(text1);
				window.draw(text3);
				window.display();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				break;
			}
		}
		if (f)
		{
			Y.name = find(Y.id + 1)->name;
			Y.id++;
		}
	}
	void check(string num, sf::RenderWindow& window)
	{
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
					window.close();
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					//window.clear(sf::Color::Black);
					break;
				}
			}
			Pokemon* S = find(num);
			if (S != nullptr)
			{
				window.clear(sf::Color::Black);
				Evolve(*S, window);
			}
			else
			{
				text1.setFont(ar);
				window.clear(sf::Color::Black);
				string a = "NOT FOUND";
				text1.setString(a);
				window.draw(text1);
			}
			window.display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				break;
			}
		}
	}
	void show(sf::RenderWindow& window) {


		check(b, window);
	}
	void main2(sf::RenderWindow& window)
	{
		initialize();
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
					window.close();
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
				{
					t(window);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					break;
				}
			}
				string a = "Welcome to Pokedex";
				sf::Text t1;
				t1.setString(a);
				ar.loadFromFile("arial.ttf");
				t1.setFont(ar);
				t1.setCharacterSize(40);
				t1.setPosition(sf::Vector2f(50, 50));
				window.clear();
				window.draw(t1);
				string b="Press X to continue";
				t1.setString(b);
				t1.setPosition(sf::Vector2f(200, 200));
				window.draw(t1);
				window.display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				break;
			}
		}
	}
	void t(sf::RenderWindow& window) {
		textbox box1(15, sf::Color::White, true);

		sf::Text text;
		text.setFont(ar);

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::TextEntered:

					ar.loadFromFile("arial.ttf");
					box1.setfont(ar);
					box1.setpos(100, 100);
					box1.typedon(event);
					b = box1.gettext();
					window.clear();

				}
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				{

					show(window);

				}
				if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
					window.close();

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					break;
				}
			}



			window.clear();
			text.setString("Enter POKEMON ID");
			text.setPosition(sf::Vector2f(20, 20));
			window.draw(text);
			box1.draw(window);
			window.display();
			 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					break;
				}
		}

	}



};



