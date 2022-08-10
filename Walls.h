#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h> 

class Walls
{
public:
	Walls();

	void render(sf::RenderTarget& game_window);
	void update(sf::RenderTarget& game_window);

private:
	sf::RectangleShape top;
	sf::RectangleShape bottom;
	float width = 50.f;
	float topLength;
	float bottomLength;
	int movement = 690;

	void initWalls();
	void randHeight();
};

