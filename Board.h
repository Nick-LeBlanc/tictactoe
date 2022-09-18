#pragma once
#include <SFML\Graphics.hpp>

class Board{
public:
	Board() {
		this->initBoard();
	};

	void render(sf::RenderTarget& game_window) {
		game_window.draw(this->line1);
		game_window.draw(this->line2);
		game_window.draw(this->line3);
		game_window.draw(this->line4);
	}

	~Board() {};
private:
	sf::RectangleShape line1;
	sf::RectangleShape line2;
	sf::RectangleShape line3;
	sf::RectangleShape line4;


	void initBoard() {
		sf::Vector2f size_horizontal = { 501, 10 };
		sf::Vector2f size_vertical = { 10, 501 };

		line1.setFillColor(sf::Color::White);
		line1.setPosition(0,157);
		line1.setSize(size_horizontal);
		
		line2.setFillColor(sf::Color::White);
		line2.setPosition(0, 324);
		line2.setSize(size_horizontal);
		
		line3.setFillColor(sf::Color::White);
		line3.setPosition(157, 0);
		line3.setSize(size_vertical);

		line4.setFillColor(sf::Color::White);
		line4.setPosition(324, 0);
		line4.setSize(size_vertical);
		
	};
};

