#include <iostream>
#include <SFML\Graphics.hpp>



int main()
{

    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(false);


    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //logic here

        window.clear();
        
        //draw things here

        window.display();
    }

    return 0;
}