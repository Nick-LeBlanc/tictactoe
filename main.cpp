#include <iostream>
#include <SFML\Graphics.hpp>
#include "Player.h"
#include "Walls.h"


int main()
{
    //player box
    int height = 480, width = 640;



    //setup window
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);

    //init player and walls
    Player Player(sf::Color::Green, 20.f);
    Walls Walls;
    
    //game loop
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //game logic
        //player movement -- he jumps
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            Player.setVelocity(-10.f);

        //wall movement


        //clear screen
        window.clear();

        Player.update(window);
        Walls.update(window);
        

        //display things
        window.display();


    }

    return 0;
}