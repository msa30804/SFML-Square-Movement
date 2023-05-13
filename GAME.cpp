#include "GAME.h"
//publi functions
void GAME::run()
{
	
	while (window.isOpen())
	{
		processEvents();

		render();
		update();
	}
	
}

//private functions
void GAME::processEvents()
{
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				handlemovements(keytime, event.key.code);
			}
		}
	}
}
//movement of square
void GAME::handlemovements(int& keytime, Keyboard::Key key)
{
    if (keytime < 1)
    {
        keytime++;
    }

    const float moveSpeed = 25.f;
    switch (key) {
    case Keyboard::A:
        if (keytime >= 1)
        {
            square.move(-moveSpeed, 0.f);
            keytime = 0;
        }
        break;
    case Keyboard::D:
        if (keytime >= 1)
        {
            square.move(moveSpeed, 0.f);
            keytime = 0;
        }
        break;
    case Keyboard::S:
        if (keytime >= 1)
        {
            square.move(0.f, moveSpeed);
            keytime = 0;
        }
        break;
    case Keyboard::W:
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
    else if (squareBounds.left + squareBounds.width > window.getSize().x) {
        square.setPosition(window.getSize().x - squareBounds.width, square.getPosition().y);
    }
    if (squareBounds.top < 0.f) {
        square.setPosition(square.getPosition().x, 0.f);
    }
    else if (squareBounds.top + squareBounds.height > window.getSize().y) {
        square.setPosition(square.getPosition().x, window.getSize().y - squareBounds.height);
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
	window.clear(sf::Color::Cyan);
	// Draw objects here
	window.draw(square);
	// showing Window
	window.display();
}

void GAME::update()
{
	//update logic here
	
}
	



