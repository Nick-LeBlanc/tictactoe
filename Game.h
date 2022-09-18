#pragma once
#include <SFML\Graphics.hpp>
#include "LogicTest.h"
#include "Board.h"
#include "Pieces.h"

class Game
{
public:
    Game() {
        this->window.create({ 501, 501 }, Title);
        this->window.setFramerateLimit(60);
        this->window.setVerticalSyncEnabled(false);

        initText();
    };


	void run(){
        while (this->window.isOpen()) {
            sf::Event event;
            while (this->window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    this->window.close();
            }

            this->logic(event, this->window);

            this->window.clear();

            this->display(this->window);

            this->window.display();
        }
	};

    ~Game() {
    };
private:
	sf::RenderWindow window;
    std::string Title = "TicTacToe";
    LogicTest test;
    Board Board;
    int state = 0;
    sf::Font font;
    sf::Text text;
    X X;
    O O;
    char first, second, winner;
    char sqaures[3][3] = { {'1','4','7'},{'2','5','8'},{'3','6','9'} };
    bool first_player = true;

    void initText() {
        if (!font.loadFromFile("C:\\Users\\nickl\\Downloads\\OpenSans.ttf"))
            {
                std::cout << "No fonts?\n";
            }
            //--------------------------------------------------
            text.setFont(font); // font is a sf::Font

            text.setString("Press Space Bar to play!");
            text.setCharacterSize(24); // in pixels, not points!
            text.setFillColor(sf::Color::White);
            text.setStyle(sf::Text::Bold);
            text.setOrigin({140,12});
            text.setPosition({250,225});
    }

    void changeText(std::string input) {
        this->text.setString(input);
        text.setOrigin({ this->text.getLocalBounds().width / 2 ,
                           this->text.getLocalBounds().height / 2});
    }

    void logic(sf::Event &event, sf::RenderWindow &window) {
        switch (this->state)
        {
        case 0:
            //init menu
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                changeText("Who goes first: X's or O's");
            }

            switch (event.key.code)
            {
            case (sf::Keyboard::Key::X):
                first = 'X', second = 'O';
                state = 1;
                break;
            case (sf::Keyboard::Key::O):
                first = 'O', second = 'X';
                state = 1;
                break;
            default:
                break;
            }


        break;
            //playing state
        case 1:
            /*
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                std::cout << "x: " << sf::Mouse::getPosition(window).x << std::endl;
                std::cout << "y: " << sf::Mouse::getPosition(window).y << std::endl;
            }
            */

            //player turns
            if (this->first_player) {
                turn(first);
                checkWin(first);
            }
            else {
                turn(second);
                checkWin(second);
            }

        break;

        //win state
        case 3:

            switch (event.key.code)
            {
            case (sf::Keyboard::Key::Y):
                reset();
                break;
            case (sf::Keyboard::Key::N):
                window.close();
                break;
            }
        break;
        //draw state
        case 4:
            switch (event.key.code)
            {
            case (sf::Keyboard::Key::Y):
                reset();
                break;
            case (sf::Keyboard::Key::N):
                window.close();
                break;
            }
            
        break;
        }
    }

    void display(sf::RenderWindow& game_window) {
        switch (this->state)
        {
        //init menu
        case 0:

            game_window.draw(this->text);
            break;

        //playing state
        case 1:
            Board.render(game_window);
            renderSquares(game_window);
            break;

        //win state

        case 3:
            Board.render(game_window);
            renderSquares(game_window);
            changeText(("Do you want to play again? Y/N"));
            this->text.setFillColor(sf::Color::Red);
            game_window.draw(this->text);
            this->text.setFillColor(sf::Color::White);

        break;

        //draw state
        case 4:
            changeText(("Draw. Play again? Y/N"));
            this->text.setFillColor(sf::Color::Red);
            game_window.draw(this->text);
            this->text.setFillColor(sf::Color::White);

        break;
        }
    }

    void turn(char player) {

        if (sqaure(0, 0, 157, 157)) {
            //std::cout << "top left\n";
            if (!(this->sqaures[0][0] == 'X' || this->sqaures[0][0] == 'O')) {
                this->sqaures[0][0] = player;
                this->first_player = !this->first_player;
            }
        }
        if (sqaure(167, 0, 324, 157)) {
            //std::cout << "top middle\n";
            if (!(this->sqaures[1][0] == 'X' || this->sqaures[1][0] == 'O')) {
                this->sqaures[1][0] = player;
                this->first_player = !this->first_player;
            }
        }
        if (sqaure(334, 0, 501, 157)) {
            //std::cout << "top right\n";
            if (!(this->sqaures[2][0] == 'X' || this->sqaures[2][0] == 'O')){
                this->sqaures[2][0] = player;
                this->first_player = !this->first_player;
            }
        }

        if (sqaure(0, 167, 157, 324)) {
            //std::cout << "middle left\n";
            if (!(this->sqaures[0][1] == 'X' || this->sqaures[0][1] == 'O')) {
                this->sqaures[0][1] = player;
                this->first_player = !this->first_player;
            }
        }
        if (sqaure(167, 167, 324, 324)) {
            //std::cout << "middle\n";
            if (!(this->sqaures[1][1] == 'X' || this->sqaures[1][1] == 'O')){
                this->sqaures[1][1] = player;
                this->first_player = !this->first_player;
            }
        }
        if (sqaure(334, 167, 501, 324)) {
            //std::cout << "middle right\n";
            if (!(this->sqaures[2][1] == 'X' || this->sqaures[2][1] == 'O')){
                this->sqaures[2][1] = player;
                this->first_player = !this->first_player;
            }
        }

        if (sqaure(0, 334, 157, 501)) {
            //std::cout << "bottom left\n";
            if (!(this->sqaures[0][2] == 'X' || this->sqaures[0][2] == 'O')){
                this->sqaures[0][2] = player;
                this->first_player = !this->first_player;
            }
        }
        if (sqaure(167, 334, 324, 501)) {
            //std::cout << "bottom middle\n";
            if (!(this->sqaures[1][2] == 'X' || this->sqaures[1][2] == 'O')){
                this->sqaures[1][2] = player;
                this->first_player = !this->first_player;
            }
        }
        if (sqaure(334, 334, 501, 501)) {
            //std::cout << "bottom right\n";
            if (!(this->sqaures[2][2] == 'X' || this->sqaures[2][2] == 'O')){
                this->sqaures[2][2] = player;
                this->first_player = !this->first_player;
            }
        }
    };

    bool sqaure(int x, int y, int x2, int y2) {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (sf::Mouse::getPosition(window).x > x && sf::Mouse::getPosition(window).x < x2)
                if (sf::Mouse::getPosition(window).y > y && sf::Mouse::getPosition(window).y < y2) {
                    return true;
                }
        }
        return false;
    }

    void checkWin(char player) {
        for (int i = 0; i < 3; i++) {
            if (this->sqaures[i][0] == this->sqaures[i][1] && this->sqaures[i][0] == this->sqaures[i][2]) {
                this->state = 3;
                this->winner = player;

            }
            if (this->sqaures[0][i] == this->sqaures[1][i] && this->sqaures[0][i] == this->sqaures[2][i]) {
                this->state = 3;
                this->winner = player;

            }
        }
        if (this->sqaures[0][0] == this->sqaures[1][1] && this->sqaures[1][1] == this->sqaures[2][2]) {
            this->state = 3;
            this->winner = player;

        }
        if (this->sqaures[0][2] == this->sqaures[1][1] && this->sqaures[1][1] == this->sqaures[2][0]) {
            this->state = 3;
            this->winner = player;
        }
        
        int count=0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                if (this->sqaures[i][j] != 'O' && this->sqaures[i][j] != 'X') {
                    count++;
                }
            }
        if (count <= 0) {
            state = 4;
        }
    }

    void renderSquares(sf::RenderWindow& game_window) {
        //top row---------------------------------------------------------
        if (this->sqaures[0][0] == 'X' || this->sqaures[0][0] == 'O') {
            if (this->sqaures[0][0] == 'X')
                X.render(game_window, { 78.5,78.5 });
            else if (this->sqaures[0][0] == 'O')
                O.render(game_window, { 78.5,78.5 });
        }
        if (this->sqaures[1][0] == 'X' || this->sqaures[1][0] == 'O') {
            if (this->sqaures[1][0] == 'X')
                X.render(game_window, { 250,78.5 });
            else if (this->sqaures[1][0] == 'O')
                O.render(game_window, { 250,78.5 });
        }
        if (this->sqaures[2][0] == 'X' || this->sqaures[2][0] == 'O') {
            if (this->sqaures[2][0] == 'X')
                X.render(game_window, { 417,78.5 });
            else if (this->sqaures[2][0] == 'O')
                O.render(game_window, { 417,78.5 });
        }

        //middle row------------------------------------------------------
        if (this->sqaures[0][1] == 'X' || this->sqaures[0][1] == 'O') {
            if (this->sqaures[0][1] == 'X')
                X.render(game_window, { 78.5,250 });
            else if (this->sqaures[0][1] == 'O')
                O.render(game_window, { 78.5,250 });
        }
        if (this->sqaures[1][1] == 'X' || this->sqaures[1][1] == 'O') {
            if (this->sqaures[1][1] == 'X')
                X.render(game_window, { 250,250 });
            else if (this->sqaures[1][1] == 'O')
                O.render(game_window, { 250,250 });
        }
        if (this->sqaures[2][1] == 'X' || this->sqaures[2][1] == 'O') {
            if (this->sqaures[2][1] == 'X')
                X.render(game_window, { 417,250 });
            else if (this->sqaures[2][1] == 'O')
                O.render(game_window, { 417,250 });
        }

        //bottom row------------------------------------------------------
        if (this->sqaures[0][2] == 'X' || this->sqaures[0][2] == 'O') {
            if (this->sqaures[0][2] == 'X')
                X.render(game_window, { 78.5,417 });
            else if (this->sqaures[0][2] == 'O')
                O.render(game_window, { 78.5,417 });
        }
        if (this->sqaures[1][2] == 'X' || this->sqaures[1][2] == 'O') {
            if (this->sqaures[1][2] == 'X')
                X.render(game_window, { 250,417 });
            else if (this->sqaures[1][2] == 'O')
                O.render(game_window, { 250,417 });
        }
        if (this->sqaures[2][2] == 'X' || this->sqaures[2][2] == 'O') {
            if (this->sqaures[2][2] == 'X')
                X.render(game_window, { 417,417 });
            else if (this->sqaures[2][2] == 'O')
                O.render(game_window, { 417,417 });
        }
    };

    void reset() {
        this->state = 0;
        this->first = NULL, this->second = NULL;
        this->sqaures[0][0] = '1';
        this->sqaures[0][1] = '2';
        this->sqaures[0][2] = '3';
        this->sqaures[1][0] = '4';
        this->sqaures[1][1] = '5';
        this->sqaures[1][2] = '6';
        this->sqaures[2][0] = '7';
        this->sqaures[2][1] = '8';
        this->sqaures[2][2] = '9';
        changeText("Press Space Bar to play!");
    }
};

