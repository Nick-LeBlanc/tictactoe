#include "Player.h"
#include <iostream>

Player::Player(sf::Color color, float size)
{
	this->color = sf::Color::Green;
	this->size = 20.f;
	this->initTexture(this->color, this->size);
}

Player::~Player()
{
}

//public functions
void Player::render(sf::RenderTarget& game_window)
{
	game_window.draw(this->texture);
}

void Player::update(sf::RenderTarget& game_window)
{
	this->render(game_window);

	if (this->texture.getPosition().y + (this->texture.getRadius() * 2.f) < 480) {
		this->texture.move(0, this->velocity);
		this->velocity += 0.5;
	}
	else {
		this->velocity = 0;
	}
}


void Player::setVelocity(float vel)
{
	if(!(this->texture.getGlobalBounds().top < 0))
		this->velocity = vel;
	
}

//private functions
void Player::initTexture(sf::Color& color, float size)
{
	this->texture.setFillColor(color);
	this->texture.setRadius(size);
	this->texture.setPosition(320.f - (this->size / 2.f), 240.f - (this->size * 2.f));
}

