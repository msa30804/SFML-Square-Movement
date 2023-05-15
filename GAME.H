#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <ctime>
#include <vector>
#include <memory>

using namespace std;
using namespace sf;

class GAME
{
private:
    // Variables
    Vector2i mouseposwindow;

    // Unique pointer to the window
    unique_ptr<RenderWindow> window;
  

    // Key time variable to limit key presses
    int keytime = 1;
    //game logic
   

    // Rectangle shapes for the player and enemy
    std::vector<RectangleShape>enemies;
    RectangleShape square;
    RectangleShape enemy;

    // Private functions
    void pollEvents(); // Polls events for the window
    void handlemovements(Keyboard::Key key); // Handles player movements
    void initvariables(); // Initializes variables for the game
    void update(); // Updates the game
    void render(); // Renders the game to the screen

public:
    // Public functions

    // Constructor for the game
    GAME() : window(make_unique<RenderWindow>(sf::VideoMode(800, 600), "SFML Window", Style::Default)),
        square(sf::Vector2f(150, 150))
    {
        
        this->window->setFramerateLimit(60);
        initvariables();
        initfighter();
        initenemies();
    }

    // Destructor for the game
    ~GAME()
    {
        // no need to manually delete window, unique_ptr takes care of it
        //this->window->close();
    }

   

    // Game objects
    void updatemousepositions(); // Updates the mouse position
    void initfighter(); // Initializes the player character
    void initenemies(); // Initializes the enemies

    void run(); // Runs the game loop
};
