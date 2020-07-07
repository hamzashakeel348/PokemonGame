#pragma once
#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
class win {
public:
	win();
	win(const std::string& l_title, const sf::Vector2u& l_size);
	~win();
	void BeginDraw(); // Clear the win.
	void EndDraw(); // Display the changes.
	void Update();
	bool IsDone();
	bool IsFullscreen();
	void Close();
	sf::Vector2u GetwinSize();
	void ToggleFullscreen();
	void Draw(sf::Drawable& l_drawable);
	sf::RenderWindow m_win;
private:
	void Setup(const std::string& l_title,
	const sf::Vector2u& l_size);
	void Destroy();
	void Create();
	sf::Vector2u m_winSize;
	std::string m_winTitle;
	bool m_isDone;
	bool m_isFullscreen;
};

