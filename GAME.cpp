#include "GAME.h"

//publi functions
void GAME::run()
{

    while (this->window->isOpen())
    {
        pollEvents();
        this->updatemousepositions();
        //this->updateEnemies();

        render();
        update();
    }

}
void GAME::updatemousepositions()
{
    //updates the mouse positions
    //mouse position  relative to window(vector 2i)
    this->mouseposwindow = Mouse::getPosition(*this->window);
}
void GAME::initfighter()
{
    square.setPosition(400, 300);
    square.setFillColor(sf::Color::Green);
    square.setOutlineThickness(20.f);
    square.setOutlineColor(Color::Black);
}
void GAME::initenemies()
{
    this->enemy.setPosition(Vector2f(20.f, 20.f));
    this->enemy.setSize(Vector2f(110.f, 110.f));
    this->enemy.setFillColor(Color::Black);
    this->enemy.setOutlineColor(Color::Green);
    this->enemy.setOutlineThickness(2.0f);
} 
//private functions
void GAME::pollEvents()
{
    sf::Event event;
    while (this->window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            handlemovements(event.key.code);
            break;
        default:
            break;
        }
    }
}
void GAME::handlemovements( Keyboard::Key key)
{
    if (keytime < 1)
    {
        keytime++;
    }

    const float moveSpeed = 25.f;
    switch (key) {
    case Keyboard::Left:
        if (keytime >= 1)
        {
            square.move(-moveSpeed, 0.f);
            keytime = 0;
        }
        break;
    case Keyboard::Right:
        if (keytime >= 1)
        {
            square.move(moveSpeed, 0.f);
            keytime = 0;
        }
        break;
    case Keyboard::Down:
        if (keytime >= 1)
        {
            square.move(0.f, moveSpeed);
            keytime = 0;
        }
        break;
    case Keyboard::Up:
        if (keytime >= 1)
        {
            square.move(0.f, -moveSpeed);
            keytime = 0;
        }
        break;

    default:
        break;
    }

    sf::FloatRect squareBounds = square.getGlobalBounds();
    if (squareBounds.left < 0.f) {
        square.setPosition(0.f, square.getPosition().y);
    }
    else if (squareBounds.left + squareBounds.width > this->window->getSize().x) {
        square.setPosition(this->window->getSize().x - squareBounds.width, square.getPosition().y);
    }
    if (squareBounds.top < 0.f) {
        square.setPosition(square.getPosition().x, 0.f);
    }
    else if (squareBounds.top + squareBounds.height > this->window->getSize().y) {
        square.setPosition(square.getPosition().x, this->window->getSize().y - squareBounds.height);
    }

    static sf::Clock clock;  // Declare a static clock to measure time
    const float colorChangeDelay = 0.1f;  // Set the delay between color changes

    if (Mouse::isButtonPressed(Mouse::Left))
    {
        // Only change the color if enough time has elapsed
        if (clock.getElapsedTime().asSeconds() > colorChangeDelay)
        {

            square.setFillColor(Color::Yellow);
            clock.restart();  // Restart the clock to measure time again
        }
    }
    else
    {
        square.setFillColor(Color::Green);
    }
}

void GAME::render()
{
    this->window->clear();
    // Draw objects here
    //this->RenderEnemies();
    this->window->draw(square);
    this->window->draw(enemy);
    // showing Window
    this->window->display();
}

void GAME::initvariables()
{
    //game logic
    
}

void GAME::update()
{
    //update logic here
    //cout << "mouse pos : " << Mouse::getPosition(this->window).x << " " << Mouse::getPosition(this->window).y << endl;

}


