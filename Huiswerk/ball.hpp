#pragma once
#include "paddle.hpp"

class ball : public colored_object {
public:
	ball(sf::Vector2f position, int16_t direction, double speed);

	//update the position depending on the passed time
	void update(int64_t passed_time) override;

	//make sure to bounce with another ball
	void interact(std::unique_ptr<ball> & other);

	//interact with a paddle with the same color
	void interact(std::unique_ptr<paddle>& other);

	void draw(sf::RenderWindow& window)override;

	sf::CircleShape circle;
	sf::Vector2f movement;
	int16_t direction;
	int radius = 10;

private:
	//calculate the movement vector which will be added to position every update with the direction and the speed
	void set_movement(int64_t direction, double speed);
};