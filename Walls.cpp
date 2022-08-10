#include "Walls.h"

Walls::Walls()
{
	this->initWalls();
}

void Walls::render(sf::RenderTarget& game_window)
{
	game_window.draw(this->top);
	game_window.draw(this->bottom);
}

void Walls::update(sf::RenderTarget& game_window)
{
	this->render(game_window);

	this->top.setPosition(movement, 0);
	this->bottom.setPosition(movement, 345);

	this->movement -= 10;
	if (movement <= -40) {
		movement = 690;
		this->randHeight();
	}
}


//private functions
void Walls::initWalls()
{
	this->top.setFillColor(sf::Color::Red);
	this->bottom.setFillColor(sf::Color::Red);

	this->randHeight();
	//this needs fixing
	this->top.setSize(sf::Vector2f {width, this->topLength});
	this->bottom.setSize(sf::Vector2f {width,this->bottomLength});
	this->top.setPosition(movement, 0);
	this->bottom.setPosition(movement, this->topLength - 480);
}

void Walls::randHeight()
{
	//max 345
	this->topLength = rand() % 345;
	this->bottomLength = this->topLength;
	
}
