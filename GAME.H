#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<iostream>
using namespace std;
using namespace sf;
class GAME
{
private:
	
	RenderWindow window;
	int keytime = 1;
	RectangleShape square;
	 
	
	//private functions

	void processEvents();
	void handlemovements(int &keytime,Keyboard::Key key);
	

	void update();
	
	 
	void render();
	
public:
	//public functions
	GAME() : window(sf::VideoMode(800, 600), "SFML Window",Style::Default),
		square(sf::Vector2f(150, 150)) 
	{
		square.setPosition(400, 300);
		square.setFillColor(sf::Color::Green);
		square.setOutlineThickness(20.f);
		square.setOutlineColor(Color::Black);
	}

	 void run();
};

