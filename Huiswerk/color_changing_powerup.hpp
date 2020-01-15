#pragma once
#include "power_up.hpp"

class color_changing_powerup : public power_up {
public:
	color_changing_powerup(sf::Vector2f position):
		power_up{position, "color_changing_powerup.png"}
	{}

	void activate(std::unique_ptr<ball> & ball)override {
		ball->setRandomDifferentColor();
		ball->circle.setFillColor(ball->getSFMLColor());
	}
};
