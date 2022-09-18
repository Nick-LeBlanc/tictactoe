#pragma once
#include <SFML\Graphics.hpp>


class O
{
public:
	O() {
		initTexture();
	}

	void render(sf::RenderTarget& game_window, sf::Vector2f pos) {
		this->texture.setPosition(pos);
		game_window.draw(this->texture);
	};


	~O(){};
private:
	sf::CircleShape texture;

	void initTexture() {
		texture.setFillColor(sf::Color::Black);
		texture.setOutlineColor(sf::Color::White);
		texture.setOutlineThickness(10.f);
		texture.setRadius(65.f);
		texture.setOrigin({70,70});
	};
};

class X
{
public:
	X() {
		initTexture();
	}

	void render(sf::RenderTarget& game_window, sf::Vector2f pos) {
		this->line1.setPosition(pos);
		this->line2.setPosition(pos);
		game_window.draw(this->line1);
		game_window.draw(this->line2);
	}
	~X() {};
private:
	sf::RectangleShape line1;
	sf::RectangleShape line2;

	void initTexture() {
		line1.setFillColor(sf::Color::White);
		line1.setOrigin({6,75});
		line1.setSize({12,150});
		line1.rotate(45);

		line2.setFillColor(sf::Color::White);
		line2.setOrigin({ 6,75 });
		line2.setSize({ 12,150 });
		line2.rotate(-45);

	}
};


