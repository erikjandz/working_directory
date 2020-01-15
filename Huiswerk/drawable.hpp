#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <iostream>
#include <cmath>

//abstract superclass where every screen object can inherit from so that the main loop can easily draw and update it
class drawable {
public:
	drawable(sf::Vector2f position):
		position{ position }
		{}

	sf::Vector2f position;

	//function to update an object with the time in microseconds given
	virtual void update(int64_t passed_time) {}

	virtual void interact(std::unique_ptr<drawable>& other) {};
	//draw the object on the screen
	virtual void draw(sf::RenderWindow & window) {}
};