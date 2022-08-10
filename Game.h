#pragma once
#include <SFML\Graphics.hpp>
#include "LogicTest.h"

class Game
{
public:
	Game() {
        this->window.create({ 640, 480 }, Title);
        this->window.setFramerateLimit(60);
        this->window.setVerticalSyncEnabled(false);
	};


	void run(){
        while (this->window.isOpen()) {
            sf::Event event;
            while (this->window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    this->window.close();
            }

            this->logic();

            this->window.clear();

            this->display(this->window);

            this->window.display();
        }
	};

    ~Game() {};
private:
	sf::RenderWindow window;
    std::string Title = "SFML Works";
    LogicTest test;

    void logic() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            test.move(1);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            test.move(2);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            test.move(3);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            test.move(4);
    }

    void display(sf::RenderTarget& game_window) {
        test.render(game_window);
    }
};

