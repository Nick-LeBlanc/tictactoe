#pragma once
#include <SFML/Graphics.hpp>

class Player {
public:
	Player(sf::Color color, float size);
	~Player();

	void render(sf::RenderTarget& game_window);
	void update(sf::RenderTarget& game_window);
	void setVelocity(float vel);

private:
	sf::CircleShape texture;
	sf::Color color;
	float size;
	float gravity = 5;
	float velocity = 0;
	
	void initTexture(sf::Color& color, float size);
};

