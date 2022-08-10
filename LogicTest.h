#pragma once
#include <SFML\Graphics.hpp>

class LogicTest{
public:
	LogicTest() {
		this->shape.setFillColor(sf::Color::Green);
		this->shape.setRadius(50.f);
	}

	void render(sf::RenderTarget& game_window) {
		game_window.draw(this->shape);
	}

	void move(int dir) {
		//basic movement
		switch (dir)
		{
		case 1:
			this->shape.move(0,-5);
			break;
		case 2:
			this->shape.move(0, 5);
			break;
		case 3:
			this->shape.move(-5, 0);
			break;
		case 4:
			this->shape.move(5, 0);
			break;
		}
	};

	~LogicTest() {};
private:
	sf::CircleShape shape;
};

