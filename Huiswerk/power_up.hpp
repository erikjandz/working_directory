#pragma once
#include "ball.hpp"

class power_up : public drawable{
public:
	power_up(sf::Vector2f position, std::string filename);

	void interact(std::unique_ptr<ball>& other);

	void draw(sf::RenderWindow& window);

	virtual void activate(std::unique_ptr<ball >& ball) {};

	sf::Sprite sprite;
	sf::Image image;
	sf::Texture texture;
	bool collected = false;

};
