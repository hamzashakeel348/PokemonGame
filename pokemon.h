#pragma once
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <cmath>

using namespace std;
class attack {
public:
	string name;
	int no;

	attack()
	{
		name = "";
		no = 0;
	}
	attack(string n, int o)
	{
		name = n;
		no = o;
	}
	void setmoves(string n, int o)
	{
		name = n;
		no = o;
	}
	void levelup()
	{
		no *= 1.1;
	}
	void print()
	{
		cout << name << "\t" << no << endl;
	}
};



class Pokemon {
public:
	int id;
	int no_of_forms;

	string name;
	char type;
	int form;
	int tot_health, e_health;
	int level;
	int exp, reqexp;
	attack mov[4];
	//public:
	bool operator ==(Pokemon A)
	{
		if (id == A.id)
		{
			return true;
		}
		else
			return false;
	}
	bool operator > (Pokemon A)
	{
		if (id > A.id)
		{
			return true;
		}
		else
			return false;
	}
	bool operator <(Pokemon A)
	{
		if (id < A.id)
		{
			return true;
		}
		else
			return false;
	}
	string getname()
	{
		return name;
	}
	Pokemon()
	{
		name = "";
		id = 0;
		tot_health = 1;
		e_health = 0;
		level = 0;
	}
	Pokemon(string a, int i, int he)
	{
		name = a;
		id = i;
		tot_health = he;
		level = 1;
		exp = 0;
		reqexp = 1;
	}

	// setter functions

	void restorehp(int v)
	{
		e_health = e_health + v;
		if (e_health > tot_health)
			e_health = tot_health;
	}
	void attackp(Pokemon& a)
	{
		int x;
		cout << "Your Pokemon -- " << name <<" HP : "<< e_health<<endl;
		cout << "Your Opponents Pokemon -- " << a.name << " HP : " << a.e_health << endl;
		cout << "1) "<< mov[0].name << "\t" << "2) " << mov[1].name << endl;
		cout << "3) "<<mov[2].name << "\t" << "4) "<<mov[3].name << endl;
		cout << "Enter the Move No for your Pokemon" << endl;
		cin >> x;
		a.e_health = a.e_health - mov[x].no;
	}
	void oattackp(Pokemon&a)
	{
		int dmg = rand() * 100 % 4;
		e_health = e_health - mov[dmg].no;
	}
	void levelup()
	{
		if (levelup_req())
		{
			cout << endl << name << "LEVELING UP " << endl;
			level++;
			if (evolve_req())
			{
				evolve();
			}
			tot_health *= 120;
			tot_health /= 100;

			e_health *= 110;
			e_health /= 100;

			reqexp *= 130;
			reqexp /= 100;

			for (int a = 0; a < 4; a++)
			{
				mov[a].levelup();
			}
		}
	}
	bool levelup_req()
	{
		if (exp >= reqexp)
			return true;
		else
			return false;
	}
	void evolve()
	{

	}
	void levelup_candy()
	{
		level++;
		if (evolve_req())
		{
			evolve();
		}
		tot_health *= 1.2;
		e_health *= 1.1;
		reqexp *= 1.3;
		for (int a = 0; a < 4; a++)
		{
			mov[a].levelup();
		}
	}
	bool evolve_req()
	{
		if (form * 18 >= level && form < no_of_forms) // pokedex database function
			return true;
		else
			return false;
	}
	void Restore_Hp()
	{
		e_health = tot_health;
	}
	void onevsone(Pokemon A)
	{
		while (e_health > 0 && A.e_health > 0)
		{
			attackp(A);
			A.oattackp(*this);
		}
		if (e_health != 0)
		{
			exp = (exp * 110) / 100;
		}
		else
			A.exp = (A.exp * 110) / 100;
		levelup();
		A.levelup();
		cout << "BATTLE ENDS" << endl; 
	}
};

