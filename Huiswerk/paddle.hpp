#pragma once

#include "colored_object.hpp"

class paddle : public colored_object {
public:
	paddle(sf::Vector2f position, bool sideways):
		colored_object(position),
		sideways(sideways)
	{
		rectangle.setPosition(position);
		if(sideways){
			rectangle.setSize(sf::Vector2f(200, 5));
		} else{
			rectangle.setSize(sf::Vector2f(5,200));
		}
		rectangle.setFillColor(getSFMLColor());
		
	};

	bool sideways;
	sf::RectangleShape rectangle;

	//function to update an object with the time in microseconds given
	void update(int64_t passed_time, int8_t value);

	//draw the object on the screen
	void draw(sf::RenderWindow & window) override;

	void setColor(uint_fast8_t color_id) override;
};