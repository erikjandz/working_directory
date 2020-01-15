#include "power_up.hpp"

power_up::power_up(sf::Vector2f position, std::string filename) :
	drawable{ position }
{
	image.loadFromFile(filename);
	image.createMaskFromColor(sf::Color::White, 0);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setScale(sf::Vector2f(0.1, 0.1));
	sprite.setPosition(position);
}

void power_up::interact(std::unique_ptr<ball> & other) {
	//some advanced calculations to check if the powerup and the ball overlap
	if (other->position.y + other->radius >= sprite.getGlobalBounds().top && 
		other->position.y - other->radius <= sprite.getGlobalBounds().top + sprite.getGlobalBounds().height && 
		other->position.x - other->radius <= sprite.getGlobalBounds().left + sprite.getGlobalBounds().width && 
		other->position.x + other->radius >= sprite.getGlobalBounds().left) {
		//if they do, activate the effect and set the bool collected
		activate(other);
		collected = true;
	}
}

void power_up::draw(sf::RenderWindow& window){
	window.draw(sprite);
}