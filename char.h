#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <windows.h>
#include <cmath>
#include"pokemon.h"
#include<SFML/Graphics.hpp>

using namespace std;

class char_team
{
protected:

	int num;
	Pokemon* poketeam;
public:
	char_team()
	{
		int itemp;
		string stemp;
		ifstream fin;
		fin.open("team.txt");
		fin >> num;
		poketeam = new Pokemon[num];
		for (int a = 0; a < num; a++)
		{
			fin >> poketeam[a].name;
			fin >> itemp;
			poketeam[a].id = itemp;
			fin >> itemp;
			poketeam[a].tot_health = itemp;
			fin >> itemp;
			poketeam[a].e_health = itemp;
			fin >> itemp;
			poketeam[a].level = itemp;
			fin >> itemp;
			poketeam[a].exp = itemp;
			fin >> itemp;
			poketeam[a].reqexp = itemp;
			for (int x = 0; x < 4; x++)
			{
				fin >> poketeam[a].mov[x].name;
				fin >> poketeam[a].mov[x].no;
			}
		}
	}

	void Load_Opponent_Pokemon()
	{
		int itemp;
		string stemp;
		ifstream fin;
		fin.open("opteam.txt");
		fin >> num;
		poketeam = new Pokemon[num];
		for (int a = 0; a < num; a++)
		{
			fin >> poketeam[a].name;
			fin >> itemp;
			poketeam[a].id = itemp;
			fin >> itemp;
			poketeam[a].tot_health = itemp;
			fin >> itemp;
			poketeam[a].e_health = itemp;
			fin >> itemp;
			poketeam[a].level = itemp;
			fin >> itemp;
			poketeam[a].exp = itemp;
			fin >> itemp;
			poketeam[a].reqexp = itemp;
			for (int x = 0; x < 4; x++)
			{
				fin >> poketeam[a].mov[x].name;
				fin >> poketeam[a].mov[x].no;
			}
		}
	}




	void draw(sf::RenderWindow& window)
	{
		string a, bb, c, d, e, f, g, h, i, j, k;
		k = "Total Health:\nExisting Health:\nTotal Exp:\nExisting Exp:";
		int b, b1, b2, b3, b4;
		sf::Texture texture;
		sf::Text t;
		sf::Texture texture2;
		sf::Texture texture3;
		sf::Texture texture4;
		if (!texture.loadFromFile("tex.png"))
		{
			cout << "Error loading" << endl;
		}

		if (!texture2.loadFromFile("ven.png"))
		{
			cout << "Error loading" << endl;
		}
		sf::Sprite sprite1(texture);
		sf::Sprite sprite2(texture2);
		if (!texture3.loadFromFile("cha.png"))
		{
			cout << "Error loading" << endl;
		}
		sf::Sprite sprite3(texture3);
		if (!texture4.loadFromFile("chr.png"))
		{
			cout << "Error loading" << endl;
		}
		sf::Sprite sprite4(texture4);
		sf::Font ar;
		ar.loadFromFile("arial.ttf");
		t.setFont(ar);
		t.setStyle(sf::Text::Style::Bold);
		sprite2.setPosition(sf::Vector2f(35, 27));
		sprite3.setPosition(sf::Vector2f(290, 23));
		sprite4.setPosition(sf::Vector2f(550, -12));
		sprite2.setScale(1.3f, 1.3f);
		sprite3.setScale(1.3f, 1.3f);
		sprite4.setScale(1.6f, 1.6f);
		t.setFillColor(sf::Color::White);
		t.setOutlineColor(sf::Color::Red);
		t.setOutlineThickness(2);
		t.setCharacterSize(10);

		sf::Event event;

		while (window.isOpen())
		{
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
			for (int i = 0; i < 17; i++)
					{
						for (int j = 0; j < 12; j++)
						{
							sprite1.setPosition(i * 30, j * 30);
							window.draw(sprite1);
						}
					}
			a = poketeam[0].name;
			b2 = poketeam[0].tot_health;
			b = poketeam[0].e_health;
			b1 = poketeam[0].exp;
			b3 = poketeam[0].reqexp;
			e = to_string(b3);
			d = to_string(b2);
			bb = to_string(b);
			c = to_string(b1);

			window.draw(sprite2);
			t.setString(a);
			t.setPosition(sf::Vector2f(45, 130));
			window.draw(t);
			t.setString(k);
			t.setPosition(sf::Vector2f(20, 150));
			t.setCharacterSize(15);
			window.draw(t);
			t.setString(d);
			t.setPosition(sf::Vector2f(125, 150));
			window.draw(t);
			t.setString(bb);
			t.setPosition(sf::Vector2f(145, 167));
			window.draw(t);
			t.setString(e);
			t.setPosition(sf::Vector2f(105, 185));
			window.draw(t);
			t.setString(c);
			t.setPosition(sf::Vector2f(125, 202));
			window.draw(t);

			//pokemon2

			a = poketeam[2].name;
			b2 = poketeam[2].tot_health;
			b = poketeam[2].e_health;
			b1 = poketeam[2].exp;
			b3 = poketeam[2].reqexp;
			e = to_string(b3);
			d = to_string(b2);
			bb = to_string(b);
			c = to_string(b1);

			window.draw(sprite3);
			t.setString(a);
			t.setPosition(sf::Vector2f(315, 140));
			window.draw(t);
			t.setString(k);
			t.setPosition(sf::Vector2f(280, 160));
			t.setCharacterSize(15);
			window.draw(t);
			t.setString(d);
			t.setPosition(sf::Vector2f(395, 160));
			window.draw(t);
			t.setString(bb);
			t.setPosition(sf::Vector2f(415, 177));
			window.draw(t);
			t.setString(e);
			t.setPosition(sf::Vector2f(375, 195));
			window.draw(t);
			t.setString(c);
			t.setPosition(sf::Vector2f(395, 212));
			window.draw(t);


			//pokemon3

			a = poketeam[1].name;
			b2 = poketeam[1].tot_health;
			b = poketeam[1].e_health;
			b1 = poketeam[1].exp;
			b3 = poketeam[1].reqexp;
			e = to_string(b3);
			d = to_string(b2);
			bb = to_string(b);
			c = to_string(b1);

			window.draw(sprite4);
			t.setString(a);
			t.setPosition(sf::Vector2f(605, 140));
			window.draw(t);
			t.setString(k);
			t.setPosition(sf::Vector2f(580, 160));
			t.setCharacterSize(15);
			window.draw(t);
			t.setString(d);
			t.setPosition(sf::Vector2f(695, 160));
			window.draw(t);
			t.setString(bb);
			t.setPosition(sf::Vector2f(715, 177));
			window.draw(t);
			t.setString(e);
			t.setPosition(sf::Vector2f(675, 195));
			window.draw(t);
			t.setString(c);
			t.setPosition(sf::Vector2f(695, 212));
			window.draw(t);


			window.display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				break;
			}
		}
	}

void Pokemon_Center()
{
	for (int i = 0; i < num; i++)
	{
		poketeam[i].Restore_Hp();
	}
}

void draw2() {

}
void print()
{
	cout << "NUMBER: " << num << endl;
	for (int a = 0; a < num; a++)
	{
		cout << a + 1 << "\t" << poketeam[a].getname()
			<< "\t HP " << poketeam[a].e_health << "/" << poketeam[a].tot_health
			<< "\t EXP " << poketeam[a].exp << "/" << poketeam[a].reqexp << endl;
	}
}
void battlesimulation(char_team a, sf::RenderWindow& window)
{
	bool Ongoing_Battle = 1;
	int p_index = 0, opp_index = 2;

	sf::Texture p1, p2, bg, v, ch, cl, d, b, t, w, l;
	sf::Sprite ps1, ps2, bgs, vs, chs, cls, ds, bs, ts, wmsg, lmsg;


	w.loadFromFile("images/won.PNG");
	l.loadFromFile("images/lost.PNG");
	v.loadFromFile("images/V.PNG");
	ch.loadFromFile("images/Ch.PNG");
	cl.loadFromFile("images/Cl.PNG");
	d.loadFromFile("images/D.PNG");
	b.loadFromFile("images/B.PNG");
	t.loadFromFile("images/T.PNG");


	wmsg.setTexture(w);
	lmsg.setTexture(l);
	vs.setTexture(v);
	chs.setTexture(ch);
	cls.setTexture(cl);
	ds.setTexture(d);
	bs.setTexture(b);
	ts.setTexture(t);



	wmsg.scale(0.5, 0.5);
	lmsg.scale(0.5, 0.5);
	vs.scale(0.5, 0.5);
	chs.scale(0.5, 0.5);
	cls.scale(0.5, 0.5);
	ds.scale(0.5, 0.5);
	bs.scale(0.5, 0.5);
	ts.scale(0.5, 0.5);


	wmsg.setPosition(200, 400);
	lmsg.setPosition(200, 400);
	ps1.setPosition(100, 100);
	ps2.setPosition(550, 100);
	ps1.scale(2, 2);
	ps2.scale(2, 2);


	bg.loadFromFile("images/green.PNG");
	bgs.setTexture(bg);


	while (Ongoing_Battle) {
		window.draw(bgs);
		if (poketeam[p_index].name == "VENASAUR")
		{
			p1.loadFromFile("images/ven.PNG");
			ps1.setTexture(p1);
			vs.setPosition(100, 300);
			window.draw(vs);
		}
		else if (poketeam[p_index].name == "CHARIZARD")
		{
			p1.loadFromFile("images/cha.PNG");
			ps1.setTexture(p1);
			chs.setPosition(100, 300);
			window.draw(chs);
		}
		else if (poketeam[p_index].name == "CHARMELION")
		{
			p1.loadFromFile("images/chr.PNG");
			ps1.setTexture(p1);
			cls.setPosition(100, 300);
			window.draw(cls);
		}

		if (a.poketeam[opp_index].name == "BAYLEEF")
		{
			p2.loadFromFile("images/bayleef.PNG");
			ps2.setTexture(p2);
			bs.setPosition(550, 300);
			window.draw(bs);
		}
		else if (a.poketeam[opp_index].name == "DRAGONITE")
		{
			p2.loadFromFile("images/dragonite.PNG");
			ps2.setTexture(p2);
			ds.setPosition(550, 300);
			window.draw(ds);
		}
		else if (a.poketeam[opp_index].name == "TYPHLOSION")
		{
			p2.loadFromFile("images/typhlosion.PNG");
			ps2.setTexture(p2);
			ts.setPosition(550, 300);
			window.draw(ts);
		}


		window.draw(ps1);
		window.draw(ps2);
		window.display();

		system("CLS");
		cout << "Player Turn ! " << endl;
		this->poketeam[p_index].attackp(a.poketeam[opp_index]);
		if (a.poketeam[opp_index].e_health <= 0)
		{
			cout << a.poketeam[opp_index].name << " Has Fainted !" << endl;
			if (a.Have_All_Fainted())
			{
				cout << "Opponent is out of Pokemon , You Won !" << endl;
				window.clear();
				window.draw(bgs);
				window.draw(wmsg);
				window.display();
				Sleep(1000);
				Ongoing_Battle = false;
			}
			else
				opp_index--;
		}
		if (Ongoing_Battle)
		{
			cout << "Opponent Turn ! " << endl;
			this->poketeam[p_index].oattackp(a.poketeam[opp_index]);
			if (this->poketeam[p_index].e_health <= 0)
			{
				cout << this->poketeam[p_index].name << " Has Fainted !" << endl;
				if (this->Have_All_Fainted())
				{
					cout << "You are out of Usable Pokemon , You Lost ! " << endl;
					window.clear();
					window.draw(bgs);
					window.draw(lmsg);
					window.display();
					Sleep(1000);
					Ongoing_Battle = false;
				}
				else
					p_index++;
			}
		}
	}
}
bool Have_All_Fainted()
{
	bool check = true;
	for (int a = 0; a < num; a++)
	{
		if (poketeam[a].e_health > 0)
		{
			check = false;
			break;
		}
	}
	return check;
}
void changelocation()
{
	int val, val2;
	Pokemon temp;
	do
	{
		print();
		// Enter -1 to exit 
		cout << "ENTER POKE TO SWAP: ";
		cin >> val;
		cout << "\n SWAP WITH: ";
		cin >> val2;

		if (val != -1 && val2 != -1)
		{
			temp = poketeam[val - 1];
			poketeam[val - 1] = poketeam[val2 - 1];
			poketeam[val2 - 1] = temp;
		}

		// to see result
		print();

	} while (val != -1 && val2 != -1);
}
};
