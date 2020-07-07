#include "Game.h"

Game::Game() : m_window("Game", sf::Vector2u(800, 600)) {
	// Setting up class members.
	Is_Battle = 0;
	Is_title = 1;
	m_Player_textureD.loadFromFile("images/pdown.PNG");
	m_Player_textureL.loadFromFile("images/pleft.PNG");
	m_Player_textureR.loadFromFile("images/pright.PNG");
	m_Player_textureU.loadFromFile("images/pup.PNG");
	m_Player.setTexture(m_Player_textureD);
	m_ground_texture.loadFromFile("images/ground.JPEG");
	m_ground.setTexture(m_ground_texture);
	m_rock_texture.loadFromFile("images/rock.JPEG");
	m_rock.setTexture(m_rock_texture);
	m_nurse_texture.loadFromFile("images/nurse.PNG");
	m_nurse.setTexture(m_nurse_texture);
	m_trees_texture.loadFromFile("images/trees.PNG");
	m_trees.setTexture(m_trees_texture);
	m_opponent_texture.loadFromFile("images/op.PNG");
	m_opponent.setTexture(m_opponent_texture);
	m_grass_texture.loadFromFile("images/grass2.JFIF");
	m_grass.setTexture(m_grass_texture);
	m_house_texture.loadFromFile("images/house2.JPEG");
	m_house.setTexture(m_house_texture);
	m_mart_texture.loadFromFile("images/house1.JPEG");
	m_mart.setTexture(m_mart_texture);
	m_pokecen_texture.loadFromFile("images/pokecen.PNG");
	m_pokecen.setTexture(m_pokecen_texture);
	m_Player.scale(1.80, 1.80);
	m_nurse.scale(1.75, 1.75);
	m_opponent.scale(2.5, 2.5);
	m_grass.scale(2, 2);
	m_house.scale(0.80, 0.80);
	m_mart.scale(0.80, 0.80);
	m_pokecen.scale(0.80, 0.80);
	m_trees.scale(1.60, 1.60);
	m_nurse.scale(1.25, 1.25);
	m_ground.scale(0.75, 0.75);
	m_increment = sf::Vector2f(450, 450);
	Gym_Leader_team.Load_Opponent_Pokemon();
}


Game::~Game() {}

void Game::Update() {
	m_window.Update(); // Update window events.
	MovePlayer();
}

void Game::MovePlayer() {
	HandleInput();
}

void Game::DrawMap() {

	for (float i = 0; i < 600; i = i + 50)
	{
		for (float j = 0; j < 800; j = j + 50)
		{
			m_grass.setPosition(j, i);
			m_window.Draw(m_grass);
		}
	}

	m_Player.setPosition(m_increment);
	m_house.setPosition(100, 200);
	m_opponent.setPosition(280, 300);
	m_pokecen.setPosition(340, 0);
	m_nurse.setPosition(340, 140);
	m_mart.setPosition(550, 300);
	m_trees.setPosition(320, 520);
	m_ground.setPosition(190, 0);
	m_window.Draw(m_house);
	m_window.Draw(m_mart);
	m_window.Draw(m_pokecen);
	m_window.Draw(m_opponent);
	m_window.Draw(m_trees);
	m_trees.setPosition(0, 520);
	m_window.Draw(m_trees);
	m_window.Draw(m_ground);
	m_ground.setPosition(90, 0);
	m_window.Draw(m_ground);
	m_window.Draw(m_nurse);
	m_window.Draw(m_Player);
	/*button icon("M E N U", 0, 0, 7, sf::Color::Black, sf::Color::Black);
	sf::Font ar;
	ar.loadFromFile("fonts/blk.ttf");
	icon.setFont(ar);
	icon.setbcolor(sf::Color::Black);
	icon.setpos(620, 10);*/
	m_trees.setPosition(580, 10);
	m_window.Draw(m_trees);
	/*icon.Setsize(150, 40);
	icon.setText(" M E N U ");
	icon.ScaleText(4, 4);
	icon.settcolor(sf::Color::White);*/
	//icon.draw(m_window.m_win);
}

void Game::Title_Screen()
{
	sf::Texture h_texture;
    sf::Texture t_texture;
	sf::Texture e_texture;

	h_texture.loadFromFile("images/Home.JPG");
	t_texture.loadFromFile("images/title.PNG");
	e_texture.loadFromFile("images/space.JPG");

	sf::Sprite home(h_texture);
	sf::Sprite title(t_texture);
	sf::Sprite enter(e_texture);


	home.scale(0.68, 0.68);
	home.setPosition(0, 30);

	title.setPosition(0,0);
	title.scale(0.75, 0.75);

	enter.setPosition(0, 520);
	enter.scale(0.75, 0.75);

	m_window.Draw(home);
	m_window.Draw(title);
	m_window.Draw(enter);
}

void Game :: Draw_Battle_Simulation()
{
	Player_team.battlesimulation(Gym_Leader_team, m_window.m_win);
}


void Game::HandleInput()
{
	menu u;

	sf::Vector2f opponent(300, 300);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_Player.setTexture(m_Player_textureD);
		if (m_increment.y < 460)
			m_increment.y += 0.50;
		if (m_Player.getGlobalBounds().intersects(m_house.getGlobalBounds()) || m_Player.getGlobalBounds().intersects(m_mart.getGlobalBounds()) || m_Player.getGlobalBounds().intersects(m_pokecen.getGlobalBounds()))
		{
			m_increment.y -= 10;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_Player.setTexture(m_Player_textureU);
		if (m_increment.y > 0.0)
			m_increment.y -= 0.50;
		if (m_Player.getGlobalBounds().intersects(m_house.getGlobalBounds()) || m_Player.getGlobalBounds().intersects(m_mart.getGlobalBounds()) || m_Player.getGlobalBounds().intersects(m_pokecen.getGlobalBounds()))
		{
			m_increment.y += 10;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_Player.setTexture(m_Player_textureL);
		if (m_increment.x > 0)
			m_increment.x -= 1;
		if (m_Player.getGlobalBounds().intersects(m_house.getGlobalBounds()) || m_Player.getGlobalBounds().intersects(m_mart.getGlobalBounds()) || m_Player.getGlobalBounds().intersects(m_pokecen.getGlobalBounds()))
		{
			m_increment.x += 10;
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_Player.setTexture(m_Player_textureR);
		if (m_increment.x < 750)
			m_increment.x += 0.50;
		if (m_Player.getGlobalBounds().intersects(m_house.getGlobalBounds()) || m_Player.getGlobalBounds().intersects(m_mart.getGlobalBounds()) || m_Player.getGlobalBounds().intersects(m_pokecen.getGlobalBounds()))
		{
			m_increment.x -= 10;
		}
	}
	if (m_Player.getGlobalBounds().intersects(m_opponent.getGlobalBounds()) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		// Start the Battle Simulation
		cout << "Collision detected" << endl;
		Is_Battle = 1;
	}
	if (m_Player.getGlobalBounds().intersects(m_nurse.getGlobalBounds()) && sf::Keyboard::isKeyPressed(sf::Keyboard::LControl))
	{
		// Interaction with Nurse Joy Restore Party Hp
		cout << "Pokemon Healed" << endl;
		Player_team.Pokemon_Center();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::M))
	{
		u.men(m_window.m_win);
	}
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
					m_window.m_win.close();
	if (Is_title && sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		Is_title = 0;
	}

}

void Game::Render() {
	m_window.BeginDraw(); // Clear.
	if (Is_title)
	{
		Title_Screen();
	}
	else if (Is_Battle)
	{
		Draw_Battle_Simulation();
		Gym_Leader_team.Pokemon_Center();
		Is_Battle = 0;
	}
	else
		DrawMap();
	m_window.EndDraw(); // Display.
}


