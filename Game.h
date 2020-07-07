#pragma once
#include <sfml/Audio.hpp>
#include <iostream>
#include <string>
#include <sfml/Graphics.hpp>
#include "win.h"
#include "button.h"
#include"menu.h"
class Game {
public:
	Game();
	~Game();
	void HandleInput();
	void Update();
	void Render();
	void Draw_Battle_Simulation();
	void Title_Screen();
	win* GetWindow();
	win m_window;
private:
	void MovePlayer();
	void DrawMap();
	bool Is_Battle;
	bool Is_title;
	sf::Texture m_Player_textureD;
	sf::Texture m_Player_textureU;
	sf::Texture m_Player_textureL;
	sf::Texture m_Player_textureR;
	sf::Texture m_grass_texture;
	sf::Texture m_house_texture;
	sf::Texture m_mart_texture;
	sf::Texture m_rock_texture;
	sf::Texture m_nurse_texture;
	sf::Texture m_trees_texture;
	sf::Texture m_ground_texture;
	sf::Texture m_pokecen_texture;
	sf::Texture m_opponent_texture;
	sf::Vector2f m_increment;
	sf::Sprite m_Player;
	sf::Sprite m_grass;
	sf::Sprite m_house;
	sf::Sprite m_nurse;
	sf::Sprite m_mart;
	sf::Sprite m_rock;
	sf::Sprite m_trees;
	sf::Sprite m_ground;
	sf::Sprite m_pokecen;
	sf::Sprite m_opponent;
	char_team Player_team;
	char_team Gym_Leader_team;
};

