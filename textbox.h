#include<iostream>
#include<SFML\Graphics.hpp>
#include<sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

using namespace std;
class textbox{
private:
	sf::Text text;
	ostringstream te;
	bool isSelected;
	bool haslimit;
	int limit; 
public:
	textbox(){
		isSelected=false;
		haslimit=false;
	}
	textbox(int size, sf::Color color, bool sel)
	{
		text.setCharacterSize(size);
		text.setColor(color);
		isSelected=sel;
		if(sel)
		{
			text.setString("_");
		}
		else
		{
			text.setString("");
		}
	}

	void setfont(sf::Font &font)
	{
		text.setFont(font);
	}
	void setpos(int x,int y)
	{
		text.setPosition(sf::Vector2f(x,y));
	}

	void setlimit(bool tof)
	{
		haslimit=tof;
	}
	void setlimit(bool tof,int li)
	{
		haslimit=tof;
		limit=li-1;
	}

	void typedon(sf::Event input)
	{int x=te.str().length();

		if(isSelected)
		{
			int chartype=input.text.unicode;
			if(chartype<128)
			{
				if(haslimit)
				{
					if(te.str().length()<=limit){
						inputlogic(chartype);
					}
					else if(x>limit && chartype==DELETE_KEY){
						deletelast();
					}
				}
				else{
					inputlogic(chartype);
				}
			}
		}
	}

	void setselected(bool se)
	{
		isSelected=se;
		if(!se)
		{
			string s=te.str();
			string n="";
			int x=s.length()-1;
			for(int i=0;i<x;i++)
			{
				n+=s[i];
			}
			text.setString(n);
		}

	}


	string gettext()
	{
		return te.str();
	}

	void draw(sf::RenderWindow &window)
	{
		window.draw(text);
	}
	void inputlogic(int chart)
	{
		if(chart!=DELETE_KEY && chart!=ENTER_KEY && chart!= ESCAPE_KEY)
		{
			te<<static_cast<char>(chart);
		}
		else if(chart== DELETE_KEY)
		{
			if(te.str().length()>0)
			{
				deletelast();
			}
		}
		text.setString(te.str()+"_");
	}


	void deletelast(){
		string s=te.str();
		string n="";
		int x=s.length()-1;
		for(int i=0;i<x;i++)
		{
			n+=s[i];
		}
		te.str("");
		te<<n;

		text.setString(te.str());
	}

};