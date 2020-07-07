#include "win.h"
win::win() {
	Setup("win", sf::Vector2u(640, 480));
}
win::win(const std::string& l_title,
	const sf::Vector2u& l_size){
	Setup(l_title, l_size);
}
win::~win() { Destroy(); }

void win::Setup(const std::string &l_title, const sf::Vector2u& l_size)
{
	m_winTitle = l_title;
	m_winSize = l_size;
	m_isFullscreen = false;
	m_isDone = false;
	Create();
}


void win::Close()
{
	m_win.close();
}

void win::Create() {
	auto style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
	m_win.create(sf::VideoMode(m_winSize.x,m_winSize.y,32),m_winTitle,style);
}
void win::Destroy() {
	m_win.close();
}

void win::Update() {
	sf::Event event;
	while (m_win.pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			m_isDone = true;
		}
		else if (event.type == sf::Event::KeyPressed &&
			event.key.code == sf::Keyboard::F5)
		{
			ToggleFullscreen();
		}
	}
}

void win::ToggleFullscreen() {
	m_isFullscreen = !m_isFullscreen;
	Destroy();
	Create();
}

void win::BeginDraw() { m_win.clear(sf::Color::Black); }
void win::EndDraw() { m_win.display(); }

bool win::IsDone() { return m_isDone; }
bool win::IsFullscreen() { return m_isFullscreen; }
sf::Vector2u win::GetwinSize() { return m_winSize; }
void win::Draw(sf::Drawable& l_drawable) {
	m_win.draw(l_drawable);
}