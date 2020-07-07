#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <windows.h>
#include <cmath>
#include"pokemon.h"
#include<SFML/Graphics.hpp>

using namespace std;
class object
{
protected:
	int quantity;
	int price;
public:
	virtual void print()
	{
		cout << "IM WORKING \n";
	}
	object(int q = 0)
	{
		quantity = q;
	}
	void inc(int a) // for purchase or found 
	{
		quantity += a;
	}
	virtual void work(Pokemon A)
	{

	}
};

class potions : public object
{
public:
	potions(int quantity) : object(quantity)
	{

	}
	virtual void print()
	{

	}
};

class n_potion : public potions
{
protected:
	int heal;
public:
	void work(Pokemon A)
	{
		A.restorehp(heal);
	}
	void print()
	{
		cout << "NORMAL POTIONS - Q:" << quantity << endl;
	}
	n_potion(int q) :potions(q)
	{
		heal = 20;
		price = 100;
	}
};

class rare_candy : public object
{
protected:

public:
	void work(Pokemon A)
	{
		A.levelup_candy();
	}
	void print()
	{
		cout << "CANDIES" << endl << endl;
		cout << "RARE CANDY - Q:" << quantity << endl;
	}
	rare_candy(int q) : object(q)
	{
	}
};

class s_potion : public potions
{
protected:
	int heal;
public:
	void work(Pokemon A)
	{
		A.restorehp(heal);
	}
	void print()
	{
		cout << "SUPER POTIONS - Q:" << quantity << endl << endl;
	}
	s_potion(int q) : potions(q)
	{
		heal = 50;
		price = 200;
	}
};

class h_potion : public potions
{
protected:
	int heal;
public:
	void work(Pokemon A)
	{
		A.restorehp(heal);
	}
	void print()
	{
		cout << "HYPER POTIONS - Q:" << quantity << endl;
	}
	h_potion(int q) :potions(q)
	{
		heal = 100;
		price = 320;
	}
};

class balls : public object
{

public:
	balls(int quantity) : object(quantity)
	{

	}
};

class pokeballs : public balls
{
protected:
	int prob;
public:
	pokeballs(int quantity) : balls(quantity)
	{
		prob = 55;
		price = 150;
	}
	bool iscapture()
	{
		if (rand() * 100 <= prob)
			return true;
		else
			return false;
	}
	void work(Pokemon A)
	{
		if (iscapture() == true)
		{
			//	cout << "CONGRATS, YOU CAPTURED " << A.getname();
			quantity--;
			//	poke = new Pokemon;
			//	poke = &A;
		}
		else
			cout << A.getname() << "BROKE FREE :((" << endl;

	}
	void print()
	{
		cout << "BALLS" << endl << endl;
		cout << "POKEBALL - Q:" << quantity << endl;
	}
};

class greatballs : public balls
{
protected:
	int prob;
public:
	greatballs(int quantity) : balls(quantity)
	{
		prob = 75;
		price = 275;
	}
	bool iscapture()
	{
		if (rand() * 100 <= prob)
			return true;
		else
			return false;
	}
	void work(Pokemon A)
	{
		if (iscapture() == true)
		{
			//	cout << "CONGRATS, YOU CAPTURED " << A.name();
			quantity--;
			//	poke = new pokemon;
			//	*poke = pokemon;
		}
		else
		{
		}
		cout << A.name << "BROKE FREE :((" << endl;
	}
	void print()
	{
		cout << "GREATBALL - Q:" << quantity << endl << endl;
	}
};

class masterballs : public balls
{
protected:
	int prob;
public:
	masterballs(int quantity) : balls(quantity)
	{
		prob = 100;
		price = 450;
	}
	bool iscapture()
	{
		if (rand() * 100 <= prob)
			return true;
		else
			return false;
	}
	void work(Pokemon A)
	{
		if (iscapture() == true)
		{
			//cout << "CONGRATS, YOU CAPTURED " << A.getname();
			quantity--;
			//	poke = new pokemon;
			//	*poke = pokemon;
		}
		else
			cout << A.name << "BROKE FREE :((" << endl;

	}
	void print()
	{
		cout << "MASTERBALL - Q:" << quantity << endl;
	}
};

class BAG
{
public:
	vector <object*> items;

	void add_item(object* A)
	{
		items.push_back(A);
	}
	void print()
	{
		for (vector<object*>::iterator it = items.begin(); it != items.end(); ++it)
			printing(*(it));
	}
	void printing(object* A)
	{
		A->print();
	}
	void set(sf::RenderWindow& window)
	{


		BAG A;
		object* S = new n_potion(5);
		object* M = new h_potion(10);
		object* N = new pokeballs(20);
		object* p = new masterballs(5);
		object* o = new greatballs(3);
		object* s = new s_potion(8);
		object* r = new rare_candy(12);
		cout << "\t\t\tWELCOME TO BAG" << endl << endl;
		cout << "Follow are the CREDENTIALS for BAG" << endl;
		cout << "POTIONS" << endl << endl;
		A.add_item(M);
		A.add_item(S);
		A.add_item(s);


		A.add_item(N);
		A.add_item(p);
		A.add_item(o);

		A.add_item(r);
		A.print();

		cout << endl;
		cout << "Press ESCAPE to Again Use the Menu" << endl;
		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
					window.close();
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					system("CLS");
					break;
				}
			}

			//A.printing(*(A.items.begin()));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				system("CLS");
				break;
			}

		}
	}

};
