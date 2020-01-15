#include "ball.hpp"

ball::ball(sf::Vector2f position, int16_t direction, double speed):
	colored_object{position}
	{
		circle = sf::CircleShape();
		circle.setOrigin(sf::Vector2f{ 10,10 });
		circle.setPosition(position);
		circle.setRadius(radius);
		circle.setFillColor( getSFMLColor() );
		set_movement(direction, speed);
	}

void ball::set_movement(int64_t direction, double speed) {
	movement.x = cos(direction * 3.14159265 / 180) * speed;
	movement.y = sin(direction * 3.14159265 / 180) * speed;
}

void ball::update(int64_t passed_time) {
	position.x += movement.x * (passed_time / 1000000.0);
	position.y += movement.y * (passed_time / 1000000.0);
}

void ball::interact(std::unique_ptr<ball> & other) {
	//some advanced algebra to calculate if they collide and to change movement after that
	float differencex = position.x - other->position.x;
	float differencey = position.y - other->position.y;
	if (differencex * differencex + differencey * differencey <= (radius + other->radius) * (radius + other->radius)){
		if (differencex < 0) {
			differencex *= -1;
		}
		if (differencey < 0) {
			differencey *= -1;
		}
		if (differencex > differencey) {
			movement.x *= -1;
		}
		else if (differencex < differencey) {
			movement.y *= -1;
		}
	}
}

void ball::interact(std::unique_ptr<paddle>& other) {
	//if you intersect with the paddle
	if (color == other->color) {
		if (position.y + radius >= other->position.y && position.y - radius <= other->position.y + other->rectangle.getSize().y && position.x + radius >= other->position.x && position.x - radius <= other->position.x + other->rectangle.getSize().x) {
			if (other->sideways) {
				movement.y *= -1;
			}
			else {
				movement.x *= -1;
			}
			setRandomDifferentColor();
			circle.setFillColor(getSFMLColor());

		}
	}
}

void ball::draw(sf::RenderWindow& window) {
	circle.setPosition(position);
	window.draw(circle);
}
	